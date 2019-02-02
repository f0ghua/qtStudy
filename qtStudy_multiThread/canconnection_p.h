#ifndef CANCONNECTION_P_H
#define CANCONNECTION_P_H

#include "canconnection.h"
#include "lfqueue.h"
#include "xbusframe.h"

#include <QThread>

class CANConnectionPrivate
{
    Q_DECLARE_PUBLIC(CANConnection)
public:
    CANConnectionPrivate(CANConnection *parent,
                         QString devName,
                         CANCon::Type type,
                         int rxQLen,
                         int txQLen);
    ~CANConnectionPrivate();
    static int allocId();
    static void freeId(int id);
    static QVector<bool> m_idPool;

    CANConnection * const q_ptr;
    QThread *m_pThread = NULL;
    QString m_devName;
    QString m_devInfo;
    CANCon::Type m_type;
    int m_id = -1;
    bool m_isStarted = false;
    bool m_isActive = false;
    LFQueue<XBusFrame> m_rxQueue;
    LFQueue<XBusFrame> m_txQueue;
    quint64 m_txCount = 0;
    quint64 m_rxCount = 0;
    quint64 m_txErrCount = 0;
    quint64 m_rxErrCount = 0;
};

#endif // CANCONNECTION_P_H
