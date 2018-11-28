#include "jydevice.h"
//#include "xmodbustcpclient.h"
#include "xmodbusmtcpclient.h"
#include "xmodbusmudpclient.h"
#include "utils.h"

#include <QEventLoop>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(APP_JY, "app.jydevice")
Q_LOGGING_CATEGORY(APP_JY_LOW, "app.jydevice.lowlevel")

class JYDevicePrivate : public QObject
{
    Q_DECLARE_PUBLIC(JYDevice)
public:
    JYDevicePrivate(JYDevice *parent);
    JYDevicePrivate(const QString &address, int port, JYDevice *parent);
    virtual ~JYDevicePrivate();

    void initModbusDevice();
    int connectToDevice(const QString &address, int port);
    void onStateChanged(QModbusDevice::State state);
    int devWriteRegister(int devid, int reg, quint16 value);
    QModbusReply *devWriteRegisterAsync(int devid, int reg, quint16 value);
    QModbusReply *devWriteRegistersAsync(int devid, int reg, const QVector<quint16> &values);
    QModbusReply *devWriteMCHexString(int devid, const QString &hexString);
    QModbusReply *devReadRegistersAsync(int devid, int reg, int number);

    JYDevice * const q_ptr;
    QString m_address;
    int m_port;
    QModbusClient *m_modbusDevice = NULL;
    QModbusDevice::State m_state = QModbusDevice::UnconnectedState;
};

JYDevicePrivate::JYDevicePrivate(JYDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(JYDevice);

    initModbusDevice();
}

JYDevicePrivate::JYDevicePrivate(const QString &address, int port, JYDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(JYDevice);

    initModbusDevice();
    connectToDevice(address, port);
}

JYDevicePrivate::~JYDevicePrivate()
{

}

void JYDevicePrivate::initModbusDevice()
{
    Q_Q(JYDevice);

    //m_modbusDevice = new XModbusSerialTcpClient(q);
    m_modbusDevice = new XModbusSerialUdpClient(q);
    m_modbusDevice->setNumberOfRetries(1);
    m_modbusDevice->setTimeout(200);

    connect(m_modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
            qCWarning(APP_JY) << "Error occurred: " << m_modbusDevice->errorString();
        });
    connect(m_modbusDevice, &QModbusClient::stateChanged, this, &JYDevicePrivate::onStateChanged);
}

int JYDevicePrivate::connectToDevice(const QString &address, int port)
{
    Q_Q(JYDevice);

    m_address = address;
    m_port = port;

    m_modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, address);
    m_modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);

    qCDebug(APP_JY) << "About to connect to" << address << port;
    if (!m_modbusDevice->connectDevice()) {
        qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        return -1;
    }

    return 0;
}

void JYDevicePrivate::onStateChanged(QModbusDevice::State state)
{
    m_state = state;

    switch (state) {
    case QModbusDevice::UnconnectedState:
        qCDebug(APP_JY) << QObject::tr("dev[%1:%2] entered unconnected state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ConnectingState:
        qCDebug(APP_JY) << QObject::tr("dev[%1:%2] entered connecting state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ConnectedState:
        qCDebug(APP_JY) << QObject::tr("dev[%1:%2] entered connected state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ClosingState:
        qCDebug(APP_JY) << QObject::tr("dev[%1:%2] entered closing state.").\
                           arg(m_address).arg(m_port);
        break;
    }
}

QModbusReply *JYDevicePrivate::devReadRegistersAsync(int devid, int reg, int number)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_JY) << "JYDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return NULL;
    }

    QModbusDataUnit readUnit = QModbusDataUnit(QModbusDataUnit::Coils, reg, number);
    QModbusReply *reply = m_modbusDevice->sendReadRequest(readUnit, devid);

    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] rxWB devid = %3, reg = %4, number = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).arg(number);

    return reply;
}

int JYDevicePrivate::devWriteRegister(int devid, int reg, quint16 value)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_JY) << "JYDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return -1;
    }

    QVector<quint16> values(1, value);
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::Coils, reg, values);
    QModbusReply *reply = m_modbusDevice->sendWriteRequest(writeUnit, devid);

    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] txWB devid = %3, reg = %4, value =").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg) << writeUnit.values();

    QEventLoop loop;
    auto connection = QObject::connect(reply, &QModbusReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    QByteArray replyData = reply->rawResult().data();
    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] rxWB devid = %3, reg = %4, adu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(replyData.toHex(' ').constData());

    if (reply->error() != QModbusDevice::NoError) {
        qCWarning(APP_JY) << "Reply error: " << reply->errorString();
        delete reply;
        return -1;
    }

    reply->deleteLater();

    return 0;
}

QModbusReply * JYDevicePrivate::devWriteRegisterAsync(int devid, int reg, quint16 value)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_JY) << "JYDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return NULL;
    }

    QVector<quint16> values(1, value);
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::Coils, reg, values);
    QModbusReply *reply = m_modbusDevice->sendWriteRequest(writeUnit, devid);

    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] txWA devid = %3, reg = %4, value =").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg) << writeUnit.values();

    return reply;
}

QModbusReply *JYDevicePrivate::devWriteRegistersAsync(int devid, int reg, const QVector<quint16> &values)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_JY) << "JYDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return NULL;
    }

    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::Coils, reg, values);
    QModbusReply *reply = m_modbusDevice->sendWriteRequest(writeUnit, devid);

    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] txWA devid = %3, reg = %4, value =").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg) << writeUnit.values();

    return reply;
}

QModbusReply *JYDevicePrivate::devWriteMCHexString(int devid, const QString &hexString)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_JY) << "JYDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_JY) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return NULL;
    }

    QModbusRequest request(QModbusRequest::WriteMultipleCoils,
                QByteArray::fromHex(hexString.toLatin1().data()));
    QModbusReply *reply = m_modbusDevice->sendRawRequest(request, devid);

    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] txWA devid = %3, hexStr = %4").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(hexString);


    return reply;
}

JYDevice::JYDevice(QObject *parent)
    : QObject(parent)
    , d_ptr(new JYDevicePrivate(this))
{
    Q_D(JYDevice);
}

JYDevice::JYDevice(const QString &address, int port, QObject *parent)
    : QObject(parent)
    , d_ptr(new JYDevicePrivate(address, port, this))
{
    Q_D(JYDevice);
}

JYDevice::~JYDevice()
{
    //delete d_ptr;
}

JYDevice::JYDevice(JYDevicePrivate &dd, QObject *parent)
    : d_ptr(&dd)
{

}

QString JYDevice::address() const
{
    Q_D(const JYDevice);
    return d->m_address;
}

int JYDevice::port() const
{
    Q_D(const JYDevice);
    return d->m_port;
}

int JYDevice::devReadRegistersAsync(int devid, int reg, int number)
{
    Q_D(JYDevice);

    QModbusReply *reply = d->devReadRegistersAsync(devid, reg, number);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        QVector<quint16> values;
        QByteArray replyData = reply->rawResult().data();

        qCDebug(APP_JY) << QObject::tr("dev[%1:%2] rxWA devid = %3, reg = %4, adu = %5").\
                            arg(d->m_address).arg(d->m_port).\
                            arg(devid).\
                            arg(reg).\
                            arg(replyData.toHex(' ').constData());

        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_JY) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }

        const QModbusDataUnit unit = reply->result();
        for (uint i = 0; i < unit.valueCount(); i++) {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i).
                    arg(QString::number(unit.value(i), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            qCDebug(APP_JY) << entry;
        }
        values = unit.values();

        QString addressPair = d->m_address + ":" + QString::number(d->m_port);
        emit responseValueGet(addressPair, devid, reg, values);

        reply->deleteLater();
    });

    return 0;
}

QModbusReply *JYDevice::devReadRegistersAsyncEx(int devid, int reg, int number)
{
    Q_D(JYDevice);

    QModbusReply *reply = d->devReadRegistersAsync(devid, reg, number);
    if (!reply) {
        return NULL;
    }

    return reply;
}

int JYDevice::devWriteRegister(int devid, int reg, quint16 value)
{
    Q_D(JYDevice);

    return d->devWriteRegister(devid, reg, value);
}

int JYDevice::devWriteRegisterAsync(int devid, int reg, quint16 value)
{
    Q_D(JYDevice);

    QModbusReply *reply = d->devWriteRegisterAsync(devid, reg, value);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_JY) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }
        
        reply->deleteLater();
    });

    return 0;
}

int JYDevice::devWriteRegistersAsync(int devid, int reg, const QVector<quint16> &values)
{
    Q_D(JYDevice);

    QModbusReply *reply = d->devWriteRegistersAsync(devid, reg, values);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_JY) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }
        
        reply->deleteLater();
    });

    return 0;
}

int JYDevice::devWriteMCHexString(int devid, const QString &hexString)
{
    Q_D(JYDevice);

    QModbusReply *reply = d->devWriteMCHexString(devid, hexString);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_JY) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }
        
        reply->deleteLater();
    });

    return 0;
}

bool JYDevice::connectDevice()
{
    Q_D(JYDevice);

    return d->m_modbusDevice->connectDevice();
}

bool JYDevice::connectToDevice(const QString &address, int port)
{
    Q_D(JYDevice);

    return d->connectToDevice(address, port);
}

bool JYDevice::isConnected()
{
    Q_D(JYDevice);
#if 0//ndef F_NO_DEBUG
    qCDebug(APP_JY) << QObject::tr("dev[%1:%2] isConnected checked, state = %3").\
                        arg(d->m_address).arg(d->m_port).arg(d->m_state);
#endif
    return (d->m_state == QModbusDevice::ConnectedState);
}
