#include "canconnection.h"
#include "canconnection_p.h"

QVector<bool> CANConnectionPrivate::m_idPool(UCHAR_MAX, true);

CANConnectionPrivate::CANConnectionPrivate(CANConnection *parent,
                                           QString devName,
                                           CANCon::Type type,
                                           int rxQLen,
                                           int txQLen)
    : q_ptr(parent)
    , m_devName(devName)
    , m_type(type)
    , m_id(allocId())
{
    Q_Q(CANConnection);

    m_rxQueue.setSize(rxQLen);
    m_txQueue.setSize(txQLen);

    m_pThread = new QThread();
    // run in main thread, move self to a thread
    q->moveToThread(m_pThread);
    // We can't delete the thread object in destructor since the destructor should be called in thread context
    QObject::connect(q, &CANConnection::finished, m_pThread, &QThread::quit);
    QObject::connect(m_pThread, &QThread::finished, m_pThread, &QThread::deleteLater);
    m_pThread->start(QThread::HighPriority);
}

CANConnectionPrivate::~CANConnectionPrivate()
{
    /* stop and delete thread */
#ifndef F_NO_DEBUG
    qDebug() << "CANConnectionPrivate destructed in thread " << QThread::currentThreadId();
#endif
    freeId(m_id);
    if(m_pThread) {
        //m_pThread->quit();
        //m_pThread->wait();
        //delete m_pThread;
        m_pThread = NULL;
    }

}

int CANConnectionPrivate::allocId()
{
    for (int i = 0; i < m_idPool.size(); i++) {
        if (m_idPool.at(i)) {
            m_idPool[i] = false;
            return i;
        }
    }

    return -1;
}

void CANConnectionPrivate::freeId(int id)
{
    m_idPool[id] = true;
}

CANConnection::CANConnection(QString devName, CANCon::Type type, int rxQLen, int txQLen)
    : d_ptr(new CANConnectionPrivate(this, devName, type, rxQLen, txQLen))
{
    Q_D(CANConnection);

#ifndef F_NO_DEBUG
    qDebug() << "CANConnection in Thread : " << QThread::currentThreadId();
#endif
    qRegisterMetaType<XBusFrame>("XBusFrame");

    start();
}

CANConnection::~CANConnection()
{
#ifndef F_NO_DEBUG
    qDebug() << "CANConnection destructed in thread " << QThread::currentThreadId();
#endif
    stop();
    delete d_ptr;
}

QString CANConnection::devName() const
{
    return d_ptr->m_devName;
}

QString CANConnection::devInfo() const
{
    return d_ptr->m_devInfo;
}

void CANConnection::setDevInfo(QString devInfo)
{
    d_ptr->m_devInfo = devInfo;
}

int CANConnection::id() const
{
    return d_ptr->m_id;
}

void CANConnection::setActive(bool isActive)
{
    d_ptr->m_isActive = isActive;
}

bool CANConnection::isActive() const
{
    return d_ptr->m_isActive;
}

QThread *CANConnection::getThread() const
{
    return d_ptr->m_pThread;
}

LFQueue<XBusFrame>& CANConnection::getRxQueue()
{
    return d_ptr->m_rxQueue;
}

LFQueue<XBusFrame>& CANConnection::getTxQueue()
{
    return d_ptr->m_txQueue;
}

bool CANConnection::hasOutgoingFrames() const
{
    return (d_ptr->m_txQueue.peek() != NULL);
}

quint64 CANConnection::txCount() const
{
    return d_ptr->m_txCount;
}

void CANConnection::setTxCount(int v)
{
    if (v < 0) {
        d_ptr->m_txCount++;
    } else {
        d_ptr->m_txCount = v;
    }
}

quint64 CANConnection::rxCount() const
{
    return d_ptr->m_rxCount;
}

void CANConnection::setRxCount(int v)
{
    if (v < 0) {
        d_ptr->m_rxCount++;
    } else {
        d_ptr->m_rxCount = v;
    }
}

quint64 CANConnection::rxErrCount() const
{
    return d_ptr->m_rxErrCount;
}

void CANConnection::setRxErrCount(int v)
{
    if (v < 0) {
        d_ptr->m_rxErrCount++;
    } else {
        d_ptr->m_rxErrCount = v;
    }
}

quint64 CANConnection::txErrCount() const
{
    return d_ptr->m_txErrCount;
}

void CANConnection::setTxErrCount(int v)
{
    if (v < 0) {
        d_ptr->m_txErrCount++;
    } else {
        d_ptr->m_txErrCount = v;
    }
}

void CANConnection::start()
{
    Q_D(CANConnection);
}

void CANConnection::stop()
{
    Q_D(CANConnection);
}

void CANConnection::open()
{
    Q_D(CANConnection);

    if(d->m_pThread && (d->m_pThread != QThread::currentThread())) {

        QMetaObject::invokeMethod(this, "open",
                                  Qt::BlockingQueuedConnection);
        return;
    }

    // run in child thread by slot call
    return piOpen();
}

void CANConnection::close()
{
    Q_D(CANConnection);

    if(d->m_pThread && (d->m_pThread != QThread::currentThread())) {
        setDevInfo("");
        QMetaObject::invokeMethod(this, "close",
                                  Qt::BlockingQueuedConnection);

        emit closed(id());

        return;
    }

    // run in child thread by slot call
    return piClose();
}

bool CANConnection::sendFrame(const XBusFrame &frame)
{
    Q_D(CANConnection);

    if( d->m_pThread && (d->m_pThread != QThread::currentThread()) )
    {
        bool ret;
        QMetaObject::invokeMethod(this, "sendFrame",
                                  Qt::BlockingQueuedConnection,
                                  Q_RETURN_ARG(bool, ret),
                                  Q_ARG(const XBusFrame&, frame));
        return ret;
    }

    // run in child thread
    return piSendFrame(frame);
}
