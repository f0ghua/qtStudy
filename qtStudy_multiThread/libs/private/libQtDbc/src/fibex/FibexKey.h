#ifndef FIBEXKEY_H
#define FIBEXKEY_H

#include <QtMath>
#include <QHash>
#include <QPair>

class FibexFrameKey
{
public:
    FibexFrameKey(qint32 slotId, qint16 baseCycle, qint16 cycleRepetition)
        : m_slotId(slotId)
        , m_baseCycle(baseCycle)
        , m_cycleRepetition(cycleRepetition)
    {}

    friend bool operator==(const FibexFrameKey &e1, const FibexFrameKey &e2);
    friend quint32 qHash(const FibexFrameKey &key);

    qint32 m_slotId;
    qint16 m_baseCycle;
    qint16 m_cycleRepetition;
};

inline bool operator==(const FibexFrameKey &e1, const FibexFrameKey &e2)
{
    return (e1.m_slotId == e2.m_slotId)
            && (e1.m_baseCycle == e2.m_baseCycle)
            && (e1.m_cycleRepetition == e2.m_cycleRepetition);
}

inline quint32 qHash(const FibexFrameKey &key)
{
    qint64 v = (((qint64)key.m_slotId) << 32)
            | (((qint64)key.m_baseCycle) << 16)
            | key.m_cycleRepetition;
    return qHash(v);
}

#endif // FIBEXKEY_H
