#include "ienginebackend.h"
#include "ienginebackend_p.h"
#include "xbusframe.h"
#include "QAppLogging.h"

#include <QTcpSocket>
#include <QHostInfo>
#include <QEventLoop>
#include <QTimer>
#include <QLoggingCategory>
#include <QThread>

IEngineBackendPrivate::IEngineBackendPrivate(IEngineBackend *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(IEngineBackend);

    qDebug() << "IEngineBackendPrivate contract in thread " << QThread::currentThreadId();
    m_wStatus.store(eIdle);
    connectToServer();
}

IEngineBackendPrivate::~IEngineBackendPrivate()
{

}

void IEngineBackendPrivate::sendCommand(COMMAND command, const void *pData, int len)
{
    if(!isSockConnected() && (command != CLIENT_CONNECT))
        return;

    int pktLen = len + sizeof(COMMAND_DATA_PACKET);
    QByteArray packet(pktLen, '\0');
    COMMAND_DATA_PACKET *pPacket = (COMMAND_DATA_PACKET *)(packet.data());
    pPacket->command = command;
    pPacket->size = pktLen;
    if(pData != NULL) { /* some commands can have no data (CLIENT_DISCONNECT) */
        memcpy(pPacket->data, pData, len); /* copy data to the packet */
    }

#ifndef F_NO_DEBUG
    {
        QLOG_INFO() << QObject::tr("txCmd: c=%1, s=%2, d=[%3]").\
                               arg(pPacket->command).\
                               arg(pPacket->size-5).\
                               arg(QByteArray(pPacket->data, pPacket->size-5).toHex(' ').constData());
    }
#endif

    m_socket->write(packet);
}

bool IEngineBackendPrivate::sendData(COMMAND command, const void *pData, int len)
{
    Q_Q(IEngineBackend);

    if (!q->isConnected()) {
        return false;
    }

    qint32 pktLen = len + sizeof(DEVICE_DATA_PACKET) + sizeof(COMMAND_DATA_PACKET);
    QByteArray packet(pktLen, '\0');
    COMMAND_DATA_PACKET *pPacket = (COMMAND_DATA_PACKET *)(packet.data());
    DEVICE_DATA_PACKET *pDeviceData = (DEVICE_DATA_PACKET *) (pPacket->data);

    pDeviceData->devId = m_connectedDeviceId;
    pDeviceData->size = len;
    pPacket->command = command;
    pPacket->size = pktLen;

    if(pData != NULL) {
        memcpy(pDeviceData->data, pData, len);
    }

#ifndef F_NO_DEBUG
    {
        qCDebug(ican_driver) << tr("txData: s=%1, d=[%2]").\
                                arg(pDeviceData->size).\
                                arg(QByteArray(pDeviceData->data, pDeviceData->size).toHex(' ').constData());
    }
#endif
    m_socket->write(packet);

    return true;
}

bool IEngineBackendPrivate::connectToServer()
{
    Q_Q(IEngineBackend);

    if(m_socket == NULL) {
#ifndef F_NO_DEBUG
        QLOG_INFO() << QObject::tr("create a new socket");
#endif
        m_socket = new QTcpSocket(this);
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(handleReceivedData()));
        connect(m_socket, SIGNAL(disconnected()), this, SLOT(handleSockDisconnected()));
    }
#ifndef F_NO_DEBUG
    QLOG_INFO() << QObject::tr("try connecting to %1:%2").arg(m_remoteIp).arg(m_remotePort);
#endif
    m_socket->connectToHost(/*QHostAddress::LocalHost*/m_remoteIp, m_remotePort);
    m_socket->waitForConnected(100);

    if (m_socket->state() != QAbstractSocket::ConnectedState)
        return false;

    setWStatus(eSocketConnected);
    q->setActive(true);

    QString hn = QHostInfo::localHostName();
    sendCommand(CLIENT_CONNECT, hn.toLatin1().data(), hn.size());

    return true;
}

void IEngineBackendPrivate::handleSockDisconnected()
{
    Q_Q(IEngineBackend);

#ifndef F_NO_DEBUG
    QLOG_INFO() << QObject::tr("socket disconnected");
#endif
    setWStatus(eIdle);
    q->setActive(false);
}

bool IEngineBackendPrivate::connectDevice(const QString &devName)
{
    Q_Q(IEngineBackend);

    if (!isSockConnected()) {
        connectToServer();
    }
    sendCommand(CONNECT_TO_DEVICE, devName.toLatin1().data(), devName.size());

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(q, &IEngineBackend::devConnected, &loop, &QEventLoop::quit);
    timer.start(200);
    loop.exec();

    if (!timer.isActive() || (m_connectedDeviceId == -1)) {
        return false;
    }

    return true;
}

bool IEngineBackendPrivate::disconnectDevice()
{
    Q_Q(IEngineBackend);

    if (m_connectedDeviceId >= 0 ) {
        sendCommand(DISCONNECT_FROM_DEVICE, &m_connectedDeviceId, sizeof(m_connectedDeviceId));
    }

#if 0 // iengine doesn't reponse the command, should we support later?
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(q, &IEngineBackend::devDisconnected, &loop, &QEventLoop::quit);
    timer.start(200);
    loop.exec();

    if (!timer.isActive() || (m_connectedDeviceId != -1)) {
        return false;
    }

    return true;
#else
    //close();
    emit q->devDisconnected();
    return true;
#endif
}

void IEngineBackendPrivate::open()
{
    Q_Q(IEngineBackend);
    connectToServer();
    connectDevice(q->devName());
}

void IEngineBackendPrivate::close()
{
    if (m_socket != NULL) {
        m_socket->flush();
        m_socket->close();
        delete m_socket;
        m_socket = NULL;
    }

    m_connectedDeviceId = -1;
    setWStatus(eIdle);
}

void IEngineBackendPrivate::handleReceivedData()
{
    if(!isSockConnected())
        return;

    QByteArray data = m_socket->readAll();
    m_receivedData.append(data);

    COMMAND_DATA_PACKET *pCmdData;
    quint32 len = m_receivedData.size();

    //qCDebug(ican_driver) << QObject::tr("rxData[%1]: d = %2").arg(len).arg(m_receivedData.toHex().constData());

    while(len > 0) {
        pCmdData = (COMMAND_DATA_PACKET *)(m_receivedData.constData());
        if ((len < sizeof(COMMAND_DATA_PACKET)) ||
                (len < pCmdData->size)) { //partially data
            break;
        }

        processResponse(pCmdData);
        len -= pCmdData->size;
        m_receivedData.remove(0, pCmdData->size);
    }
}

void IEngineBackendPrivate::processResponse(COMMAND_DATA_PACKET *commandData)
{
    Q_Q(IEngineBackend);

    DEVICE_DATA_PACKET *pDeviceData;

#ifndef F_NO_DEBUG
    if (commandData->command != DEVICE_DATA) {
        QLOG_INFO() << QObject::tr("rxCmd: c=%1, s=%2, d=[%3]").\
                    arg(commandData->command).\
                    arg(commandData->size-5).\
                    arg(QByteArray(commandData->data, commandData->size-5).toHex(' ').constData());
    }
#endif

    switch(commandData->command) {

    case CLIENT_CONNECT:
        setWStatus(eClientConnected);
        break;

    case REQUEST_VERSION:
        break;

    case DEVICE_DATA:
    {
        DEVICE_DATA_PACKET *pDeviceData = (DEVICE_DATA_PACKET *) (commandData->data);
        processDeviceData(pDeviceData);
        break;
    }
    case REQUEST_DEVICES:
        processRequseDevices(commandData->data);
        break;

    case CONNECT_TO_DEVICE:
        processConnectToDevice(commandData->data);
        break;

    case DISCONNECT_FROM_DEVICE:
        /*
        m_connectedDeviceId = -1;
        emit q->devConnected();
        */
        break;

    case DEVICE_LIST_CHANGED:
        close();
        break;

    default:
        break;
    }
}

void IEngineBackendPrivate::processRequseDevices(QString s)
{
    QStringList ql;

    m_devList.clear();
    ql = s.split(",");

    for(int i = 0; i < ql.size() - 1; i += 2)
        m_devList << ql[i];

    emit portsChanged();
}

void IEngineBackendPrivate::processConnectToDevice(const char *data)
{
    Q_Q(IEngineBackend);
    qint32 devId = (qint32)(*data);
    if (devId == -1) {
        return;
    }

    m_connectedDeviceId = devId;
    m_receivedData.clear();
    setWStatus(eDeviceConnected);

    emit q->devConnected();
}

void IEngineBackendPrivate::processDeviceData(DEVICE_DATA_PACKET *pDeviceData)
{
    Q_Q(IEngineBackend);

    QByteArray res(pDeviceData->data, pDeviceData->size);
#ifndef F_NO_DEBUG
    qCDebug(ican_driver) << QObject::tr("rxData: s=%1, d=[%2]").\
                arg(res.size()).\
                arg(res.toHex(' ').constData());
#endif
    handleFullData(res);
}

bool IEngineBackendPrivate::handleFullData(const QByteArray &block)
{
    Q_Q(IEngineBackend);

    if (block.isEmpty()) return false;

#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("rx[%1]: %2").arg(q->devName()).arg(block.toHex(' ').constData());
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

QStringList IEngineBackendPrivate::availablePorts()
{
    m_devList.clear();

    if (!isSockConnected()) {
        connectToServer();
    }
    sendCommand(REQUEST_DEVICES, NULL, 0);

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(this, &IEngineBackendPrivate::portsChanged, &loop, &QEventLoop::quit);
    timer.start(200);
    loop.exec();

    if (!timer.isActive()) {
#ifndef F_NO_DEBUG
        qCWarning(ican_driver) << "get ports timeout";
#endif
    }

    return m_devList;
}

IEngineBackend::IEngineBackend(QString devName)
    : CANConnection(devName, CANCon::FTDI_SOCKET)
    //, d_ptr(new IEngineBackendPrivate(this))
{
    qDebug() << "IEngineBackend contract in thread " << QThread::currentThreadId();
}

IEngineBackend::~IEngineBackend()
{
    qDebug() << "IEngineBackend destract in thread " << QThread::currentThreadId();
    delete d_ptr;
}

void IEngineBackend::run()
{
    d_ptr = new IEngineBackendPrivate(this);
}

bool IEngineBackend::isConnected()
{
    Q_D(IEngineBackend);

    return (d->m_wStatus.load() == IEngineBackendPrivate::eDeviceConnected);
}

QStringList IEngineBackend::availablePorts()
{
    Q_D(IEngineBackend);

    return d->availablePorts();
}

void IEngineBackend::setServerAddress(const QString &ip, int port)
{
    Q_D(IEngineBackend);

    d->m_remoteIp = ip;
    d->m_remotePort = port;

    d->close();
}

bool IEngineBackend::connectDevice(const QString &devName)
{
    Q_D(IEngineBackend);

    return d->connectDevice(devName);
}

bool IEngineBackend::disconnectDevice()
{
    Q_D(IEngineBackend);

    return d->disconnectDevice();
}

void IEngineBackend::halWrite(const QByteArray &data)
{
    Q_D(IEngineBackend);

    if (d->m_connectedDeviceId < 0)
        return;

    d->sendData(DEVICE_DATA, data.constData(), data.size());

    return;
}

void IEngineBackend::piStarted()
{
#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("piStarted run in thread ") << QThread::currentThreadId();
#endif
}

void IEngineBackend::piStop()
{
#ifndef F_NO_DEBUG
    qDebug() << QObject::tr("piStop run in thread ") << QThread::currentThreadId();
#endif
}

void IEngineBackend::piOpen()
{
    Q_D(IEngineBackend);

    d->open();
}

void IEngineBackend::piClose()
{
    Q_D(IEngineBackend);

    d->close();
}

bool IEngineBackend::piSendFrame(const XBusFrame &frame)
{
    Q_D(IEngineBackend);

    if (d->m_connectedDeviceId < 0)
        return false;

    bool ret = d->sendData(DEVICE_DATA, frame.rawData().data(), frame.rawData().size());
    if (ret) {
        setTxCount();
    } else {
        setTxErrCount();
    }
    return ret;
}

