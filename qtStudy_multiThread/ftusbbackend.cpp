#include "ftusbbackend.h"
#include "ftusbbackend_p.h"
#include "xbusframe.h"
#include "settingsmanager.h"
#include "utils.h"

#include <QCoreApplication>
#include <QWinEventNotifier>
#include <QThread>
#include <QElapsedTimer>
#include <QDebug>

#define F_NO_DEBUG
//#define TX_IN_THREAD

FTBTxWorker::FTBTxWorker(FTUSBBackend *backend)
    : m_pBackEnd(backend)
{
#ifndef F_NO_DEBUG
    qDebug() << "FTBTxWorker contruct in thread " << QThread::currentThreadId();
#endif
}

FTBTxWorker::~FTBTxWorker()
{
#ifndef F_NO_DEBUG
    qDebug() << "FTBTxWorker destruct in thread " << QThread::currentThreadId();
#endif

}

void FTBTxWorker::stop()
{
    m_isRunning = false;
}

void FTBTxWorker::run()
{
    FT_STATUS ftStatus;

#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("FTBTxWorker run in thread ") << QThread::currentThreadId();
#endif

    while(m_isRunning) {
        
        XBusFrame *frame = m_pBackEnd->getTxQueue().peek();
        if (frame) {
            FT_HANDLE ftHandle = m_pBackEnd->getFtHandle();
            DWORD bytesWritten = 0;

            ftStatus = FT_Write(ftHandle, frame->rawData().data(), frame->rawData().size(), &bytesWritten);
            if (ftStatus == FT_OK) {
                m_pBackEnd->setTxCount();
            } else {
#ifndef F_NO_DEBUG
                qWarning() << "FT_Write error";
#endif
                m_pBackEnd->setTxErrCount();
            }
            // if send fail, we just drop the frame to prevent from deadlock
            m_pBackEnd->getTxQueue().dequeue();
        } else {
            // add sleep to make cpu happy
            QThread::msleep(1);
        }
        QCoreApplication::processEvents();

        // 100000 ~ 3000; 30000 ~ 3200
        //for(int i = 0; i < 10000;i++);
    }

}

FTBInitWorker::FTBInitWorker(FTUSBBackendPrivate *bp, int timeout, QThread *thread)
    : d(bp)
    , m_timeout(timeout)
{
    moveToThread(thread);
    connect(thread, &QThread::started, this, &FTBInitWorker::run);
    connect(thread, &QThread::finished, this, &QObject::deleteLater);
}

void FTBInitWorker::workInternal()
{
    DWORD txBytes, rxBytes, eventMask;
    FT_STATUS ftStatus;
    DWORD bytesReceived = 0;
    QElapsedTimer elapsedTimer;
    elapsedTimer.start();

    d->m_tmpRxBuff.clear();
    while(!elapsedTimer.hasExpired(m_timeout)) {
        FT_GetStatus(d->m_ftHandle, &rxBytes, &txBytes, &eventMask);
        if (rxBytes > 0) {
#ifndef F_NO_DEBUG
            qDebug() << QObject::tr("rxBytes = %1").arg(rxBytes);
#endif
            ftStatus = FT_Read(d->m_ftHandle, d->m_rxBuffer, rxBytes, &bytesReceived);
            if (ftStatus == FT_OK) {
                QByteArray ba(d->m_rxBuffer, bytesReceived);
                d->m_tmpRxBuff.append(ba);
            }
        }
        QThread::msleep(1);
    }

    emit finished();
}

namespace FTBInternal {

class ReadNotifier : public QWinEventNotifier
{
    // no Q_OBJECT macro!
public:
    explicit ReadNotifier(FTUSBBackendPrivate *d, QObject *parent)
        : QWinEventNotifier(parent)
        , dptr(d)
    {
        setHandle(dptr->m_eh);
    }

protected:
    bool event(QEvent *e) override
    {
        if (e->type() == QEvent::WinEventAct) {
            dptr->startRead();
            return true;
        }
        return QWinEventNotifier::event(e);
    }

private:
    FTUSBBackendPrivate * const dptr;
};

class WriteNotifier : public QTimer
{
    // no Q_OBJECT macro!
public:
    WriteNotifier(FTUSBBackendPrivate *d, QObject *parent)
        : QTimer(parent)
        , dptr(d)
    {
        setInterval(0);
    }

protected:
    void timerEvent(QTimerEvent *e) override
    {
        if (e->timerId() == timerId()) {
            dptr->startWrite();
            return;
        }
        QTimer::timerEvent(e);
    }

private:
    FTUSBBackendPrivate * const dptr;
};

}

using namespace FTBInternal;

FTUSBBackendPrivate::FTUSBBackendPrivate(FTUSBBackend *parent)
    : q_ptr(parent)
{
    Q_Q(FTUSBBackend);
#ifndef F_NO_DEBUG
    qDebug() << "FTUSBBackendPrivate contruct in thread " << QThread::currentThreadId();
#endif
    m_rxBuffer = (char *)calloc(1, USB_CHUNK_LEN);
}

FTUSBBackendPrivate::~FTUSBBackendPrivate()
{
    Q_Q(FTUSBBackend);

#ifndef F_NO_DEBUG
    qDebug() << "FTUSBBackendPrivate destract in thread " << QThread::currentThreadId();
#endif
    close();
    free(m_rxBuffer);

    emit q->finished();
}

#ifdef INIT_IN_THREAD
void FTUSBBackendPrivate::getFTDeviceType()
{
    Q_Q(FTUSBBackend);

    unsigned char reqVer[] = {0x08, 0x92, 0xFF, 0x00};
    FT_STATUS ftStatus;
    DWORD bytesWritten = 0;

    ftStatus = FT_Write(m_ftHandle, reqVer, sizeof(reqVer), &bytesWritten);
    if (ftStatus != FT_OK) {
        return;
    }

    QThread thread;
    FTBInitWorker *worker = new FTBInitWorker(this, 100, &thread);
    thread.start();

    QEventLoop loop;
    QObject::connect(worker, &FTBInitWorker::finished, &loop, &QEventLoop::quit);
    loop.exec();

    thread.quit();
    thread.wait();

    QString devInfo;
    QByteArray prefixGetVersion = QByteArray("\x08\x92");
    QByteArray ba = getResponse(prefixGetVersion, m_tmpRxBuff);
    if (ba.size() > 2) {
        devInfo = QString::fromStdString(ba.mid(2, ba.size()-2).toStdString());
    } else {
        devInfo = QStringLiteral("error on get device info");
    }

    q->setDevInfo(devInfo);
}
#else
void FTUSBBackendPrivate::getFTDeviceType()
{
    Q_Q(FTUSBBackend);

    unsigned char reqVer[] = {0x08, 0x92, 0xFF, 0x00};
    FT_STATUS ftStatus;
    DWORD bytesWritten = 0;

    ftStatus = FT_Write(m_ftHandle, reqVer, sizeof(reqVer), &bytesWritten);
    if (ftStatus != FT_OK) {
        return;
    }

    Utils::Base::msleep(100);
    DWORD txBytes, rxBytes, eventMask;
    DWORD bytesReceived = 0;
    QString devInfo;

    FT_GetStatus(m_ftHandle, &rxBytes, &txBytes, &eventMask);
#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("FT_GetStatus rxBytes  %1").arg(rxBytes);
#endif
    if (rxBytes > 0) {
        ftStatus = FT_Read(m_ftHandle, m_rxBuffer, rxBytes, &bytesReceived);
        if (ftStatus == FT_OK) {
#ifndef F_NO_DEBUG
            qDebug() << QObject::tr("len[%1], rxbuff = %2").arg(bytesReceived).arg(QByteArray(m_rxBuffer,bytesReceived).toHex(0x20).constData());
#endif
            QByteArray prefixGetVersion = QByteArray("\x08\x92");
            QByteArray rxData(m_rxBuffer, bytesReceived);
            QByteArray ba = getResponse(prefixGetVersion, rxData);
            if (ba.size() > 2) {
                devInfo = QString::fromStdString(ba.mid(2, ba.size()-2).toStdString());
            } else {
                devInfo = QStringLiteral("error on get device info");
            }
        }
    } else {
        devInfo = QStringLiteral("error on get device info");
    }
    q->setDevInfo(devInfo);
}
#endif

void FTUSBBackendPrivate::open()
{
    Q_Q(FTUSBBackend);

    if (q->isActive()) return;

    FT_STATUS ftStatus;
    ftStatus = FT_OpenEx((void *)(q->devName().toStdString().data()),
                         FT_OPEN_BY_SERIAL_NUMBER,
                         &m_ftHandle);
    if (ftStatus != FT_OK) {
#ifndef F_NO_DEBUG
        qCritical() << QObject::tr("FT_OpenEx failed with dev %1").arg(q->devName());
#endif
        return;
    }

    ftStatus = FT_SetTimeouts(m_ftHandle, 5000, 200);
    if (ftStatus != FT_OK) {
#ifndef F_NO_DEBUG
        qWarning() << QObject::tr("FT_SetTimeouts failed with dev %1").arg(q->devName());
#endif
    }

    ftStatus = FT_SetLatencyTimer(m_ftHandle, 2);
    if (ftStatus != FT_OK) {
#ifndef F_NO_DEBUG
        qWarning() << QObject::tr("FT_SetLatencyTimer failed with dev %1").arg(q->devName());
#endif
    }

    DWORD rsize;
    ftStatus = FT_GetQueueStatus(m_ftHandle, &rsize);
    if (ftStatus != FT_OK) {
#ifndef F_NO_DEBUG
        qWarning() << QObject::tr("Unable to get Queue status");
#endif
    } else {
#ifndef F_NO_DEBUG
        qDebug() << QObject::tr("At Init there are %1 characters in read queue").arg(rsize);
#endif
    }

    ftStatus = FT_Purge(m_ftHandle, FT_PURGE_RX|FT_PURGE_TX);
    if (ftStatus != FT_OK) {
#ifndef F_NO_DEBUG
        qWarning() << QObject::tr("FT_Purge failed");
#endif
    } else {
#ifndef F_NO_DEBUG
        qDebug() << QObject::tr("FT_Purge OK");
#endif
    }

    //getFTDeviceType();

    DWORD eventMask = FT_EVENT_RXCHAR;
    m_eh = CreateEvent(NULL, false, false,
                     reinterpret_cast<LPCWSTR>(q->devName().toLatin1().data()));
    ftStatus = FT_SetEventNotification(m_ftHandle, eventMask, (PVOID)m_eh);
    if (ftStatus == FT_OK) {
    } else {
#ifndef F_NO_DEBUG
        qCritical() << "FT_SetEventNotification fail";
#endif
    }

    m_readNotifier = new ReadNotifier(this, q);
    m_readNotifier->setEnabled(true);

#ifdef TX_IN_THREAD
    startTxWorker();
#else
    m_writeNotifier = new WriteNotifier(this, q);
#endif

    q->setActive(true);
}

void FTUSBBackendPrivate::close()
{
    Q_Q(FTUSBBackend);

    if (!q->isActive()) return;
#ifdef TX_IN_THREAD
    stopTxWorker();
#else
    if (m_writeNotifier) {
        delete m_writeNotifier;
        m_writeNotifier = nullptr;
    }
#endif
    if (m_readNotifier) {
        delete m_readNotifier;
        m_readNotifier = nullptr;
    }

    FT_Close(m_ftHandle);
    m_ftHandle = nullptr;

    q->setActive(false);
}

void FTUSBBackendPrivate::startTxWorker()
{
    Q_Q(FTUSBBackend);

    m_pTxThread = new QThread();
    m_txWorker = new FTBTxWorker(q);
    m_txWorker->moveToThread(m_pTxThread);
    QObject::connect(m_pTxThread, &QThread::started, m_txWorker, &FTBTxWorker::run);
    QObject::connect(m_pTxThread, &QThread::finished, m_txWorker, &FTBTxWorker::deleteLater);
    QObject::connect(m_pTxThread, &QThread::finished, m_pTxThread, &QThread::deleteLater);
    QObject::connect(this, &FTUSBBackendPrivate::stopTx, m_txWorker, &FTBTxWorker::stop);
    m_pTxThread->start(QThread::HighPriority);
}

void FTUSBBackendPrivate::stopTxWorker()
{
    emit stopTx();

    if(m_pTxThread && (!m_pTxThread->isFinished())) {
        m_pTxThread->quit();
        if(!m_pTxThread->wait()) {
            qWarning() << "can't stop thread";
        }
        qDebug() << "TxWorker thread finished";
    }
}

bool FTUSBBackendPrivate::putFrameInRxQueue(QByteArray &block)
{
    Q_Q(FTUSBBackend);

    if (block.isEmpty()) return false;

#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("rx[%1]: %2").arg(q->devName()).arg(Utils::Base::formatByteArray(&block));
#endif

    XBusFrame *pFrame = q->getRxQueue().get();
    if (pFrame) {
        *pFrame = XBusFrame(block);
        q->setRxCount();
        q->getRxQueue().queue();
    } else {
#ifndef F_NO_DEBUG
        qDebug() << "Can't get a rxQueue frame";
#endif
        q->setRxErrCount();
        return false;
    }
    return true;
}

void FTUSBBackendPrivate::procRXChar(quint8 c)
{
    if ((c == 0xFF) && (m_ffFlag == 0)) { // first 0xFF
        m_ffFlag = 1;
        return;
    }

    if (m_ffFlag == 0) {
        m_block.append(c);
    } else {
        m_ffFlag = 0;
        if (c == 0xFF) { // 2 0xFF, the first one means escape character
            m_block.append(c);
        } else if (c == 0x00) { // end of message
            putFrameInRxQueue(m_block);
            m_block.clear();
        } else { // a new message start
            putFrameInRxQueue(m_block);
            m_block.clear();
            m_block.append(c);
        }
    }
}

// response maybe not start with a full frame end
QByteArray FTUSBBackendPrivate::getResponse(const QByteArray &prefixTag, const QByteArray &rxData)
{
    QByteArray block;
    QByteArray endTag = QByteArrayLiteral("\xFF\x00");

    int s = 0, e = 0;
    if ((s = rxData.indexOf(prefixTag)) != -1) {
        if ((e = rxData.indexOf(endTag, s + prefixTag.size())) != -1) {
            block = rxData.mid(s, e - s);
        }
    }
    return block;
}

void FTUSBBackendPrivate::startRead()
{
    Q_Q(FTUSBBackend);

    DWORD txBytes, rxBytes, eventMask;
    FT_STATUS ftStatus;
    DWORD bytesReceived = 0;

    FT_GetStatus(m_ftHandle, &rxBytes, &txBytes, &eventMask);
    if (rxBytes > 0) {
        ftStatus = FT_Read(m_ftHandle, m_rxBuffer, rxBytes, &bytesReceived);
        if (ftStatus == FT_OK) {
            Q_ASSERT(bytesReceived < USB_CHUNK_LEN);
            for (DWORD i = 0; i < bytesReceived; i++) {
                procRXChar(m_rxBuffer[i]);
            }
        } else {
            q->setRxCount();
#ifndef F_NO_DEBUG
            qWarning() << "FT_Read Failed";
#endif
        }
    }
}

void FTUSBBackendPrivate::startWrite()
{
    Q_Q(FTUSBBackend);

    if (!q->hasOutgoingFrames()) {
        m_writeNotifier->stop();
        return;
    }

    FT_STATUS ftStatus;
    XBusFrame *frame = q->getTxQueue().peek();
    if (frame) {
        DWORD bytesWritten = 0;

        ftStatus = FT_Write(m_ftHandle, frame->rawData().data(), frame->rawData().size(), &bytesWritten);
        if (ftStatus == FT_OK) {
#ifndef F_NO_DEBUG
            qDebug() << QObject::tr("tx[%1] %2").arg(q->devName()).\
                            arg(Utils::Base::formatByteArray(&frame->rawData()));
#endif
            q->setTxCount();
        } else {
#ifndef F_NO_DEBUG
            qWarning() << "FT_Write error";
#endif
            q->setTxErrCount();
        }
        // if send fail, we just drop the frame to prevent from deadlock
        q->getTxQueue().dequeue();
    }
/*
    if (q->hasOutgoingFrames()) {
        m_writeNotifier->start();
    }
*/
}


FTUSBBackend::FTUSBBackend(QString devName)
    : CANConnection(devName, CANCon::FTDI_USB)
    , d_ptr(new FTUSBBackendPrivate(this))
{

}

FTUSBBackend::~FTUSBBackend()
{
    qDebug() << "FTUSBBackend destract in thread " << QThread::currentThreadId();
    delete d_ptr;
}

FT_HANDLE FTUSBBackend::getFtHandle() const
{
    return d_ptr->m_ftHandle;
}

static bool isValidSerialNumber(QString sn)
{
    QRegularExpression rx("SZ\\d[\\dA-F]{3}");
    QRegularExpressionMatch rm = rx.match(sn);
    if (rm.hasMatch()) {
        return true;
    }
    return false;
}

QStringList FTUSBBackend::getDeviceList(bool isNumberPrepend)
{
    FT_STATUS ftStatus;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    DWORD numDevs;
    QStringList devNames;

#ifndef F_NO_DEBUG
    qDebug() << "FTUSBBackend::getDeviceList in thread " << QThread::currentThreadId();
#endif

#if 0
    quint32 devIndex = 0;
    char buffer[128];

    ftStatus = FT_ListDevices(&numDevs, NULL, FT_LIST_NUMBER_ONLY);
    if (ftStatus == FT_OK) {
        qDebug() << "FT_ListDevices numDevs = " << numDevs;
    } else {
        qDebug() << "FT_ListDevices fail";
    }
    if (isNumberPrepend) {
        devNames.append(QString::number(numDevs));
    }

    for (devIndex = 0; devIndex < numDevs; devIndex++) {
        ftStatus = FT_ListDevices((PVOID)devIndex, buffer,
                                FT_LIST_BY_INDEX|FT_OPEN_BY_SERIAL_NUMBER);
        if (ftStatus == FT_OK) {
#ifndef F_NO_DEBUG
            qDebug() << QObject::tr("buffer = %1").arg(buffer);
#endif
            if (isValidSerialNumber(buffer)) {
                devNames.append(buffer);
            }
        }
    }
#ifndef F_NO_DEBUG
    qDebug() << "devNames = " << devNames;
#endif

#else
    // create the device information list
    ftStatus = FT_CreateDeviceInfoList(&numDevs);

    if (ftStatus == FT_OK) {
#ifndef F_NO_DEBUG
        qDebug() << QObject::tr("Number of devices is %1").arg(numDevs);
#endif
    } else {
#ifndef F_NO_DEBUG
        qWarning() << QObject::tr("FT_CreateDeviceInfoList fail");
#endif
    }

    if (isNumberPrepend) {
        devNames.append(QString::number(numDevs));
    }

    if (numDevs > 0) {
        // allocate storage for list based on numDevs
        devInfo =
            (FT_DEVICE_LIST_INFO_NODE *)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
        // get the device information list
        ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);
        if (ftStatus == FT_OK) {
            bool isSerialPortSupport = false;
#ifdef SERIAL_SUPPORT
            QSettings *settings = SettingsManager::settings();
            isSerialPortSupport = settings->value(QStringLiteral("comPortEnable"), false).toBool();
#endif                
            for (DWORD i = 0; i < numDevs; i++) {
#ifndef F_NO_DEBUG
                qDebug() << QObject::tr("Dev %1").arg(i);
                qDebug() << QObject::tr("  Flags=0x%1").arg(devInfo[i].Flags, 0, 16);
                qDebug() << QObject::tr("  Type=0x%1").arg(devInfo[i].Type, 0, 16);
                qDebug() << QObject::tr("  ID=0x%1").arg(devInfo[i].ID, 0, 16);
                qDebug() << QObject::tr("  LocId=0x%1").arg(devInfo[i].LocId, 0, 16);
                qDebug() << QObject::tr("  SerialNumber=%1").arg(devInfo[i].SerialNumber);
                qDebug() << QObject::tr("  Description=%1").arg(devInfo[i].Description);
                qDebug() << QObject::tr("  ftHandle=0x%1").arg((quint32)devInfo[i].ftHandle, 0, 16);
#endif
                // prevent from non-ICITS devices detected
                if (!isSerialPortSupport) {
                    quint64 vendorId = (devInfo[i].ID&0xFFFF0000) >> 16;
                    if (vendorId != ICITS_VENDOR_ID) {
                        continue;
                    }
                }

                if (devInfo[i].SerialNumber[0] != '\0') {
                    devNames.append(devInfo[i].SerialNumber);
                }
        }
      }
    }
#endif

    return devNames;
}

void FTUSBBackend::piStarted()
{
#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("piStarted run in thread ") << QThread::currentThreadId();
#endif
}

void FTUSBBackend::piStop()
{
#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("piStop run in thread ") << QThread::currentThreadId();
#endif
}

void FTUSBBackend::piOpen()
{
    Q_D(FTUSBBackend);

    d->open();
}

void FTUSBBackend::piClose()
{
    Q_D(FTUSBBackend);

    d->close();
}

bool FTUSBBackend::piSendFrame(const XBusFrame &frame)
{
    Q_D(FTUSBBackend);

    if (!isActive()) return false;

    XBusFrame *pFrame = getTxQueue().get();
    if (pFrame) {
        *pFrame = frame;
        getTxQueue().queue();
    } else {
#ifndef F_NO_DEBUG
        qWarning() << "Can't get a txQueue frame";
#endif
        setTxErrCount();
    }

#ifndef TX_IN_THREAD
    if (!d->m_writeNotifier->isActive())
        d->m_writeNotifier->start();
#endif

    return true;
}

