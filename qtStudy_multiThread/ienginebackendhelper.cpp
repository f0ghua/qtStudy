#include "ienginebackendhelper_p.h"
#include "ienginebackendhelper.h"

#include <QTcpSocket>
#include <QHostInfo>
#include <QEventLoop>
#include <QTimer>

IEngineBackEndHelperPrivate::IEngineBackEndHelperPrivate(IEngineBackEndHelper *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(IEngineBackEndHelper);

    connectToServer();
}

IEngineBackEndHelperPrivate::~IEngineBackEndHelperPrivate()
{

}

void IEngineBackEndHelperPrivate::sendCommand(COMMAND command, const void *pdata, int plen)
{
    if(!isSockConnected() && (command != CLIENT_CONNECT))
        return;

    qint32 len = plen + sizeof(COMMAND_DATA_PACKET);
    COMMAND_DATA_PACKET *commandData = (COMMAND_DATA_PACKET *)calloc(len, 1);

    commandData->command = command;
    commandData->size = len;

    if(plen != 0 && pdata != NULL)
        memcpy(commandData->data, pdata, plen);

#ifndef F_NO_DEBUG
    {
        const char *p = (const char *)commandData;
        QByteArray baData(p, len);
        qDebug() << tr("sendCommand[%1] >> %2").arg(len).arg(baData.toHex(' ').constData());
    }
#endif
    m_socket->write((const char *)commandData, len);
    free(commandData);
}

bool IEngineBackEndHelperPrivate::connectToServer()
{
    if(m_socket == NULL) {
        m_socket = new QTcpSocket(this);
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(handleReceivedData()));
    }
    m_socket->connectToHost(QHostAddress::LocalHost, 8000);
    m_socket->waitForConnected(100);

    if (m_socket->state() != QAbstractSocket::ConnectedState)
        return false;

#ifndef F_NO_DEBUG
    qDebug()<<"CLIENT_CONNECT";
#endif
    setWStatus(eSocketConnected);
    QString hn = QHostInfo::localHostName();
    sendCommand(CLIENT_CONNECT, hn.toLatin1().data(), hn.size());

    return true;
}

void IEngineBackEndHelperPrivate::handleReceivedData()
{
    if(!isSockConnected())
        return;

    QByteArray data = m_socket->readAll();
    m_receivedData.append(data);

    COMMAND_DATA_PACKET *pCmdData;
    quint32 len = m_receivedData.size();

#ifndef F_NO_DEBUG
    //qDebug() << QObject::tr("rxData[%1]: d = %2").arg(len).arg(m_receivedData.toHex().constData());
#endif
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

void IEngineBackEndHelperPrivate::processResponse(COMMAND_DATA_PACKET *commandData)
{
    DEVICE_DATA_PACKET *pDeviceData;
#if 0//ndef F_NO_DEBUG
    qDebug() << QObject::tr("rxReq: c=%1, s=%2, d=%3").\
                arg(commandData->command).\
                arg(commandData->size).\
                arg(QByteArray(commandData->data, commandData->size-5).toHex().constData());
#endif

    switch(commandData->command) {

        case CLIENT_CONNECT:
            setWStatus(eClientConnected);
            break;

        case REQUEST_VERSION:
            break;

        case DEVICE_DATA:
            break;

        case REQUEST_DEVICES:
            processRequseDevices(commandData->data);
            break;

        case CONNECT_TO_DEVICE:
            break;

        case DEVICE_LIST_CHANGED:
            break;

        default:
#ifndef F_NO_DEBUG
            qDebug()<<"some ev" << commandData->command;
#endif
            break;
    }
}

void IEngineBackEndHelperPrivate::processRequseDevices(QString s)
{
    QStringList ql;

    m_devList.clear();
    ql = s.split(",");

    for(int i = 0; i < ql.size() - 1; i += 2)
        m_devList << ql[i];
#ifndef F_NO_DEBUG
    qDebug()<< "new update" << m_devList;
#endif
    emit portsChanged();
}

QStringList IEngineBackEndHelperPrivate::availablePorts()
{
    if (!isSockConnected()) {
        connectToServer();
    }
    sendCommand(REQUEST_DEVICES, NULL, 0);

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(this, &IEngineBackEndHelperPrivate::portsChanged, &loop, &QEventLoop::quit);
    timer.start(200);
    loop.exec();

    if (timer.isActive()) {
#ifndef F_NO_DEBUG
        qDebug()<<"get ports successfully";
#endif
    }

    return m_devList;
}

IEngineBackEndHelper::IEngineBackEndHelper(QObject *parent)
    : QObject(parent)
    , d_ptr(new IEngineBackEndHelperPrivate(this))
{
    Q_D(IEngineBackEndHelper);
}

IEngineBackEndHelper::~IEngineBackEndHelper()
{

}

QStringList IEngineBackEndHelper::availablePorts() const
{
    return d_ptr->availablePorts();
}
