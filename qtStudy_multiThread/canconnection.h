#ifndef CANCONNECTION_H
#define CANCONNECTION_H

#include "lfqueue.h"

#include <QObject>
#include <QThread>

class XBusFrame;

namespace CANCon {

    /**
     * @brief The status enum
     */
    enum Status
    {
        NOT_CONNECTED,  /*!< device is not connected */
        CONNECTED       /*!< device is connected */
    };

    enum Type
    {
        FTDI_USB,
        FTDI_SERIAL,
        FTDI_SOCKET,
        NONE
    };
}

class CANConnectionPrivate;

class CANConnection : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(CANConnection)
public:
    CANConnection(QString devName, CANCon::Type type, int rxQLen = 10000, int txQLen = 10000);
    virtual ~CANConnection();
    QString devName() const;
    QString devInfo() const;
    void setDevInfo(QString devInfo);
    int id() const;
    LFQueue<XBusFrame> &getRxQueue();
    LFQueue<XBusFrame> &getTxQueue();
    bool hasOutgoingFrames() const;
    void setActive(bool isActive);
    bool isActive() const;
	QThread *getThread() const;
    quint64 txCount() const;
    void setTxCount(int v = -1);
    quint64 rxCount() const;
    void setRxCount(int v = -1);
    quint64 rxErrCount() const;
    void setRxErrCount(int v = -1);
    quint64 txErrCount() const;
    void setTxErrCount(int v = -1);

signals:
	void finished();
    void closed(int connId);
	
public slots:
    virtual void run();
    void open();
    void close();
    bool sendFrame(const XBusFrame &frame);

protected:
    virtual void piStarted() {};
    virtual void piStop() = 0;
    virtual void piOpen() = 0;
    virtual void piClose() = 0;
    virtual bool piSendFrame(const XBusFrame &frame) = 0;

private:
    void start();
    void stop();

    CANConnectionPrivate * const d_ptr;
};

#endif // CANCONNECTION_H
