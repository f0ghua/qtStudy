#include "ngidevice.h"
#include "xmodbusaudpclient.h"
#include "utils.h"

#include <QEventLoop>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(APP_NGI, "app.ngidevice")
Q_LOGGING_CATEGORY(APP_NGI_LOW, "app.ngidevice.lowlevel")

class NgiDevicePrivate : public QObject
{
    Q_DECLARE_PUBLIC(NgiDevice)
public:
    NgiDevicePrivate(NgiDevice *parent);
    NgiDevicePrivate(const QString &address, int port, NgiDevice *parent);
    virtual ~NgiDevicePrivate();

    void initModbusDevice();
    int connectToDevice(const QString &address, int port);
    int devReadResult(int devid, int reg, QByteArray &value);
    int devWriteResult(int devid, int reg, const QByteArray &value);
    QModbusReply *devReadResultAsync(int devid, int reg);
    QModbusReply *devWriteResultAsync(int devid, int reg, const QByteArray &value);
    QModbusReply *devWriteRawDataAsync(const QByteArray &pdu);

    NgiDevice * const q_ptr;
    QString m_address;
    int m_port;
    QModbusClient *m_modbusDevice = NULL;
    QModbusDevice::State m_state = QModbusDevice::UnconnectedState;

public slots:
    void onStateChanged(QModbusDevice::State state);
};

static inline float byteArray2Float(const QByteArray &ba)
{
    quint32 v = Utils::Base::byteArray2Ux(ba, sizeof(quint32));
    return *reinterpret_cast<float *>(&v);
}

static inline QByteArray float2ByteArray(float f)
{
    quint32 v = *reinterpret_cast<quint32 *>(&f);
    return Utils::Base::ux2ByteArray(v, sizeof(v));
}

NgiDevicePrivate::NgiDevicePrivate(NgiDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(NgiDevice);

    initModbusDevice();
}

NgiDevicePrivate::NgiDevicePrivate(const QString &address, int port, NgiDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(NgiDevice);

    initModbusDevice();
    connectToDevice(address, port);
}

NgiDevicePrivate::~NgiDevicePrivate()
{

}

void NgiDevicePrivate::initModbusDevice()
{
    Q_Q(NgiDevice);

    m_modbusDevice = new XModbusAsciiUdpClient(q);
    m_modbusDevice->setNumberOfRetries(0);
    m_modbusDevice->setTimeout(200);

    connect(m_modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
            qCWarning(APP_NGI) << "Error occurred: " << m_modbusDevice->errorString();
        });
    connect(m_modbusDevice, &QModbusClient::stateChanged, this, &NgiDevicePrivate::onStateChanged);

}

int NgiDevicePrivate::connectToDevice(const QString &address, int port)
{
    Q_Q(NgiDevice);

    if (m_state == QModbusDevice::ConnectedState) {
        m_modbusDevice->disconnectDevice();
    }

    m_address = address;
    m_port = port;

    m_modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, address);
    m_modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);

    qCDebug(APP_NGI) << "About to connect to" << address << port;
    if (!m_modbusDevice->connectDevice()) {
        qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
    }

    return 0;
}

void NgiDevicePrivate::onStateChanged(QModbusDevice::State state)
{
    m_state = state;

    switch (state) {
    case QModbusDevice::UnconnectedState:
        qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] entered unconnected state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ConnectingState:
        qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] entered connecting state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ConnectedState:
        qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] entered connected state.").\
                           arg(m_address).arg(m_port);
        break;
    case QModbusDevice::ClosingState:
        qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] entered closing state.").\
                           arg(m_address).arg(m_port);
        break;
    }
}

int NgiDevicePrivate::devReadResult(int devid, int reg, QByteArray &value)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_NGI) << "NgiDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
        }
        if (m_state != QModbusDevice::ConnectedState) {
            qCWarning(APP_NGI) << "NgiDevice has not been connected";
            return -1;
        }
    }

    QByteArray pdu;
    pdu.append(Utils::Base::ux2ByteArray(reg, 2));
    pdu.append(Utils::Base::ux2ByteArray(1, 2)); // number
    QModbusRequest request(QModbusPdu::ReadHoldingRegisters, pdu);
    QModbusReply *reply = m_modbusDevice->sendRawRequest(request, devid);
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] txRB devid = %3, reg = %4, pdu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(pdu.toHex(' ').constData());
    QEventLoop loop;
    auto connection = QObject::connect(reply, &QModbusReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    QByteArray replyData = reply->rawResult().data();
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] rxRB devid = %3, reg = %4, adu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(replyData.toHex(' ').constData());

    if (reply->error() != QModbusDevice::NoError) {
        qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
        delete reply;
        return -1;
    }
    if (replyData.size() != 5) {
        delete reply;
        return -1;
    }

    value = replyData;

    reply->deleteLater();

    return 0;
}

QModbusReply *NgiDevicePrivate::devReadResultAsync(int devid, int reg)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_NGI) << "NgiDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
        }
        if (m_state != QModbusDevice::ConnectedState) {
            qCWarning(APP_NGI) << "NgiDevice has not been connected";
            return NULL;
        }
    }

    QByteArray pdu;
    pdu.append(Utils::Base::ux2ByteArray(reg, 2));
    pdu.append(Utils::Base::ux2ByteArray(1, 2)); // number
    QModbusRequest request(QModbusPdu::ReadHoldingRegisters, pdu);
    QModbusReply *reply = m_modbusDevice->sendRawRequest(request, devid);    
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] txRA devid = %3, reg = %4, pdu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(pdu.toHex(' ').constData());

    return reply;
}

int NgiDevicePrivate::devWriteResult(int devid, int reg, const QByteArray &value)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_NGI) << "NgiDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
        }
        if (m_state != QModbusDevice::ConnectedState) {
            qCWarning(APP_NGI) << "NgiDevice has not been connected";
            return -1;
        }
    }

    QByteArray pdu;
    pdu.append(Utils::Base::ux2ByteArray(reg, 2));
    pdu.append(value);
    QModbusRequest request(QModbusPdu::WriteSingleRegister, pdu);
    QModbusReply *reply = m_modbusDevice->sendRawRequest(request, devid);
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] txWB devid = %3, reg = %4, pdu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(pdu.toHex(' ').constData());
    QEventLoop loop;
    auto connection = QObject::connect(reply, &QModbusReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    QByteArray replyData = reply->rawResult().data();
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] rxWB devid = %3, reg = %4, adu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(replyData.toHex(' ').constData());
    if (reply->error() != QModbusDevice::NoError) {
        qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
        delete reply;
        return -1;
    }

    reply->deleteLater();

    return 0;
}

QModbusReply *NgiDevicePrivate::devWriteResultAsync(int devid, int reg, const QByteArray &value)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_NGI) << "NgiDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
        }
        if (m_state != QModbusDevice::ConnectedState) {
            qCWarning(APP_NGI) << "NgiDevice has not been connected";
            return NULL;
        }
    }

    QByteArray pdu;
    pdu.append(Utils::Base::ux2ByteArray(reg, 2));
    pdu.append(value);
    QModbusRequest request(QModbusPdu::WriteSingleRegister, pdu);
    QModbusReply *reply = m_modbusDevice->sendRawRequest(request, devid);
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] txWA devid = %3, reg = %4, pdu = %5").\
                        arg(m_address).arg(m_port).\
                        arg(devid).\
                        arg(reg).\
                        arg(pdu.toHex(' ').constData());
    return reply;
}

QModbusReply *NgiDevicePrivate::devWriteRawDataAsync(const QByteArray &pdu)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_NGI) << "NgiDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_NGI) << "Connect failed: " << m_modbusDevice->errorString();
        }
        if (m_state != QModbusDevice::ConnectedState) {
            qCWarning(APP_NGI) << "NgiDevice has not been connected";
            return NULL;
        }
    }

    QModbusPdu modbusPdu;
    modbusPdu.setData(pdu);
    QModbusRequest request(modbusPdu);
    XModbusAsciiUdpClient *client = qobject_cast<XModbusAsciiUdpClient *>(m_modbusDevice);
    QModbusReply *reply = client->sendRequestSimple(request, DEVADDR_DIRECT_FORWARD);
    qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] txWA devid = 0x%3, pdu = %4").\
                        arg(m_address).arg(m_port).\
                        arg(DEVADDR_DIRECT_FORWARD, 0, 16).\
                        arg(pdu.toHex(' ').constData());
    return reply;
}

NgiDevice::NgiDevice(QObject *parent)
    : QObject(parent)
    , d_ptr(new NgiDevicePrivate(this))
{
    Q_D(NgiDevice);
}

NgiDevice::NgiDevice(const QString &address, int port, QObject *parent)
    : QObject(parent)
    , d_ptr(new NgiDevicePrivate(address, port, this))
{
    Q_D(NgiDevice);
}

NgiDevice::~NgiDevice()
{
    //delete d_ptr;
}

NgiDevice::NgiDevice(NgiDevicePrivate &dd, QObject *parent)
    : d_ptr(&dd)
{

}

const QString &NgiDevice::address() const
{
    Q_D(const NgiDevice);
    return d->m_address;
}

int NgiDevice::port() const
{
    Q_D(const NgiDevice);
    return d->m_port;
}

int NgiDevice::devReadUint(int devid, int reg, uint &value)
{
    Q_D(NgiDevice);

    QByteArray result;
    int rc = d->devReadResult(devid, reg, result);
    if (rc < 0) {
        return -1;
    }
    value = Utils::Base::byteArray2Ux(result.mid(1), 4);

    return 0;
}

int NgiDevice::devReadFloat(int devid, int reg, double &value)
{
    Q_D(NgiDevice);

    QByteArray result;
    int rc = d->devReadResult(devid, reg, result);
    if (rc < 0) {
        return -1;
    }
    value = (double)byteArray2Float(result.mid(1));

    return 0;
}

int NgiDevice::devReadFloatAsync(int devid, int reg)
{
    Q_D(NgiDevice);

    QModbusReply *reply = d->devReadResultAsync(devid, reg);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        double value;
        QByteArray replyData = reply->rawResult().data();

        qCDebug(APP_NGI) << QObject::tr("dev[%1:%2] rxWA devid = %3, reg = %4, adu = %5").\
                            arg(d->m_address).arg(d->m_port).\
                            arg(devid).\
                            arg(reg).\
                            arg(replyData.toHex(' ').constData());

        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }
        if (replyData.size() != 5) {
            delete reply;
            return;
        }
        value = (double)byteArray2Float(replyData.mid(1));
        QString addressPair = d->m_address + ":" + QString::number(d->m_port);
        emit responseValueGet(addressPair, devid, reg, value);
        
        reply->deleteLater();
    });

    return 0;
}

int NgiDevice::devWriteUint(int devid, int reg, uint value)
{
    Q_D(NgiDevice);

    QByteArray ba = Utils::Base::ux2ByteArray(value, sizeof(uint));
    int rc = d->devWriteResult(devid, reg, ba);
    if (rc < 0) {
        return -1;
    }

    return 0;
}

int NgiDevice::devWriteFloat(int devid, int reg, double value)
{
    Q_D(NgiDevice);

    QByteArray ba = float2ByteArray((float)value);
    int rc = d->devWriteResult(devid, reg, ba);
    if (rc < 0) {
        return -1;
    }

    return 0;
}

int NgiDevice::devWriteUintAsync(int devid, int reg, uint value)
{
    Q_D(NgiDevice);

    QByteArray ba = Utils::Base::ux2ByteArray(value, sizeof(uint));
    QModbusReply *reply = d->devWriteResultAsync(devid, reg, ba);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
            delete reply;
            return -1;
        }
        
        reply->deleteLater();
    });

    return 0;
}

int NgiDevice::devWriteFloatAsync(int devid, int reg, double value)
{
    Q_D(NgiDevice);

    QByteArray ba = float2ByteArray((float)value);
    QModbusReply *reply = d->devWriteResultAsync(devid, reg, ba);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
            delete reply;
            return -1;
        }
        
        reply->deleteLater();
    });

    return 0;
}

QModbusReply *NgiDevice::devWriteFloatAsyncEx(int devid, int reg, double value)
{
    Q_D(NgiDevice);

    QByteArray ba = float2ByteArray((float)value);
    QModbusReply *reply = d->devWriteResultAsync(devid, reg, ba);

    return reply;
}

int NgiDevice::devWriteRawDataAsync(const QByteArray &ba)
{
    Q_D(NgiDevice);

    QModbusReply *reply = d->devWriteRawDataAsync(ba);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_NGI) << "Reply error: " << reply->errorString();
            delete reply;
            return -1;
        }
        
        reply->deleteLater();
    });

    return 0;
}

bool NgiDevice::connectDevice()
{
    Q_D(NgiDevice);

    return d->m_modbusDevice->connectDevice();
}

bool NgiDevice::connectToDevice(const QString &address, int port)
{
    Q_D(NgiDevice);

    return d->connectToDevice(address, port);
}

bool NgiDevice::isConnected()
{
    Q_D(NgiDevice);

    return (d->m_state == QModbusDevice::ConnectedState);
}

