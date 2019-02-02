#ifndef FTUSBBACKEND_P_H
#define FTUSBBACKEND_P_H

#include "ftusbbackend.h"
#include "ftd2xx.h"

#include <QThread>
#include <QTimer>

#define EVENT_HANDLE HANDLE

namespace FTBInternal {
class ReadNotifier;
class WriteNotifier;
}

class FTBInitWorker : public QObject
{
    Q_OBJECT
public:
    FTBInitWorker(FTUSBBackendPrivate *bp, int timeout, QThread *thread);
    void work()
    {
        QMetaObject::invokeMethod(this, "workInternal");
    }
public slots:
    void run() { workInternal(); }

private slots:
    void workInternal();

signals:
    void finished();

private:
    FTUSBBackendPrivate *d;
    int m_timeout;
};

class FTBTxWorker : public QObject
{
    Q_OBJECT
public:
    FTBTxWorker(FTUSBBackend *backend);
	~FTBTxWorker();
	
public slots:
    void run();
    void stop();

private:
    FTUSBBackend *m_pBackEnd;
    bool m_isRunning = true;
};

class FTUSBBackendPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(FTUSBBackend)
public:
#define USB_CHUNK_LEN (1024*1024*8)
    FTUSBBackendPrivate(FTUSBBackend *parent);
    ~FTUSBBackendPrivate();
    void getFTDeviceType();
    void open();
    void close();
    void startTxWorker();
    void stopTxWorker();
    void startRead();
    void startWrite();
	bool putFrameInRxQueue(QByteArray &block);
    void procRXChar(quint8 c);
    QByteArray getResponse(const QByteArray &prefix, const QByteArray &rxData);

    FTUSBBackend * const q_ptr;
    FT_HANDLE m_ftHandle = NULL;
    EVENT_HANDLE m_eh;
    QThread *m_pTxThread = NULL;
    FTBTxWorker *m_txWorker = NULL;
    FTBInternal::ReadNotifier *m_readNotifier = NULL;
    FTBInternal::WriteNotifier *m_writeNotifier = NULL;
    char *m_rxBuffer = NULL;
    int m_ffFlag = 0;
    QByteArray m_block;
    QByteArray m_tmpRxBuff;

signals:
    void stopTx();

};

#endif // FTUSBBACKEND_P_H
