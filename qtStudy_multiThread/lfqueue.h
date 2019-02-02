#ifndef LFQUEUE_H
#define LFQUEUE_H

#include <QObject>
#include <QDebug>


/* macros */
#define IS_EMPTY()  (  m_wIdx.load()             == m_rIdx.load() )
#define IS_FULL()   ( (m_wIdx.load()+1)%m_size    == m_rIdx.load() )


template<class T>
class LFQueue
{
public:
    LFQueue() : m_size(0), m_array(NULL){}

    ~LFQueue() {setSize(0);}

    bool setSize(int size)
    {
        if(size<0)
            return false;

        if(m_array) {
            delete[] m_array;
            m_array = NULL;
        }

        if(size>0) {
            m_array = new T[size];
            if(m_array)
                m_size = size;
            return ( m_array!=NULL );
        }

        return true;
    }

    void flush()
    {
        m_rIdx.store(0);
        m_wIdx.store(0);
    }

    T* get()
    {
        if(IS_FULL())
            return NULL;

        return &(m_array[m_wIdx.loadAcquire()]); /* prevent memory reordering (belt and braces) */
    }


    void queue()
    {
        if(IS_FULL())
            qCritical() << "BUG: queueing in full queue";

        int wIdx = m_wIdx.load();
        m_wIdx.storeRelease((wIdx+1)%m_size);
    }


    T* peek()
    {
        if(IS_EMPTY())
            return NULL;

        return &(m_array[m_rIdx.loadAcquire()]); /* prevent memory reordering (belt and braces) */
    }


    void dequeue()
    {
        if(IS_EMPTY())
            qCritical() << "BUG: dequeueing an empty queue";

        int rIdx = m_rIdx.load();
        m_rIdx.storeRelease((rIdx+1)%m_size);
    }

    int freeSize()
    {
        int rIdx = m_rIdx.loadAcquire();
        int wIdx = m_wIdx.loadAcquire();
        return (wIdx>=rIdx)?(m_size-wIdx+rIdx):(rIdx-wIdx-1);
    }

    inline bool isFull()
    {
        return IS_FULL();
    }

private:
    int m_size;
    T*  m_array;

    QAtomicInt m_rIdx;
    QAtomicInt m_wIdx;
};

#endif // LFQUEUE_H
