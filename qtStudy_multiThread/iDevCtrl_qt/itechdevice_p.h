#ifndef ITECHDEVICE_P_H
#define ITECHDEVICE_P_H

#include "itechdevice.h"

class QSerialPortReply: public QObject
{
    Q_OBJECT
public:

    bool isFinished() const
    {
        return m_finished;
    }
    QString errorString() const
    {
        return m_errorText;
    }
    void setReply(double value){
        m_reply = value;
    }

    void setFinished(bool isFinished)
    {
        m_finished = isFinished;
        if(isFinished)
            emit finished();
    }

    void setMsgType(ITechDevice::MsgType type)
    {
        m_type = type;
    }

    bool m_finished = false;
    QString m_errorText;
    QString m_info;
    double m_reply;
    ITechDevice::MsgType m_type;

signals:
    void finished();
    void errorOccurred();
};

struct QSerialPortRequest{
    QByteArray data;
    ITechDevice::MsgType type;
};

struct QueueElement {
    QueueElement() = default;
    QueueElement(QSerialPortReply *r, const QSerialPortRequest &req,  int num,
            int timeout = -1)
        : reply(r), requestPdu(req), numberOfRetries(num)
    {
        if (timeout >= 0) {
            // always the case for TCP
            timer = QSharedPointer<QTimer>::create();
            timer->setSingleShot(true);
            timer->setInterval(timeout);
        }
    }
    bool operator==(const QueueElement &other) const {
        return reply == other.reply;
    }

    QPointer<QSerialPortReply> reply;
    QSerialPortRequest requestPdu;
    int numberOfRetries;
    QSharedPointer<QTimer> timer;
    QByteArray adu;
    qint64 bytesWritten = 0;
};

#endif // ITECHDEVICE_P_H
