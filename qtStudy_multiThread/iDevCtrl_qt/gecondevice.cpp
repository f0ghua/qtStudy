#include "gecondevice.h"
#include "xmodbusrtuclient.h"
#include "utils.h"

#include <QSerialPort>
#include <QEventLoop>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(APP_GECON, "app.gecondevice")
Q_LOGGING_CATEGORY(APP_GECON_LOW, "app.gecondevice.lowlevel")

class GeconDevicePrivate : public QObject
{
    Q_DECLARE_PUBLIC(GeconDevice)
public:
    GeconDevicePrivate(GeconDevice *parent);
    GeconDevicePrivate(const QString &address, int port, GeconDevice *parent);
    virtual ~GeconDevicePrivate();

    void initModbusDevice();
    int connectToDevice(const QString &address, int port);
    QModbusReply *devReadRegistersAsync(int devid, int reg, int number);

    GeconDevice * const q_ptr;
    QString m_comPort;
    int m_baudrate;
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

GeconDevicePrivate::GeconDevicePrivate(GeconDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(GeconDevice);

    initModbusDevice();
}

GeconDevicePrivate::GeconDevicePrivate(const QString &comPort, int baudrate, GeconDevice *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(GeconDevice);

    initModbusDevice();
    connectToDevice(comPort, baudrate);
}

GeconDevicePrivate::~GeconDevicePrivate()
{

}

void GeconDevicePrivate::initModbusDevice()
{
    Q_Q(GeconDevice);

    m_modbusDevice = new XModbusRtuClient(q);
    m_modbusDevice->setNumberOfRetries(1);
    m_modbusDevice->setTimeout(200);

    connect(m_modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
            qCWarning(APP_GECON) << "Error occurred: " << m_modbusDevice->errorString();
        });
    connect(m_modbusDevice, &QModbusClient::stateChanged, this, &GeconDevicePrivate::onStateChanged);

}

int GeconDevicePrivate::connectToDevice(const QString &comPort, int baudrate)
{
    Q_Q(GeconDevice);

    if (m_state == QModbusDevice::ConnectedState) {
        m_modbusDevice->disconnectDevice();
    }

    m_comPort = comPort;
    m_baudrate = baudrate;

    m_modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, m_comPort);
    m_modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, m_baudrate);
    m_modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    m_modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    m_modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);

    qCDebug(APP_GECON) << "About to connect to" << m_comPort << m_baudrate;
    if (!m_modbusDevice->connectDevice()) {
        qCWarning(APP_GECON) << "Connect failed: " << m_modbusDevice->errorString();
    }

    return 0;
}

void GeconDevicePrivate::onStateChanged(QModbusDevice::State state)
{
    m_state = state;

    switch (state) {
    case QModbusDevice::UnconnectedState:
        qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] entered unconnected state.").\
                           arg(m_comPort).arg(m_baudrate);
        break;
    case QModbusDevice::ConnectingState:
        qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] entered connecting state.").\
                           arg(m_comPort).arg(m_baudrate);
        break;
    case QModbusDevice::ConnectedState:
        qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] entered connected state.").\
                           arg(m_comPort).arg(m_baudrate);
        break;
    case QModbusDevice::ClosingState:
        qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] entered closing state.").\
                           arg(m_comPort).arg(m_baudrate);
        break;
    }
}

QModbusReply *GeconDevicePrivate::devReadRegistersAsync(int devid, int reg, int number)
{
    if (m_state != QModbusDevice::ConnectedState) {
        qCWarning(APP_GECON) << "GeconDevice has not been connected, try to connect";
        if (!m_modbusDevice->connectDevice()) {
            qCWarning(APP_GECON) << "Connect failed: " << m_modbusDevice->errorString();
        }
        return NULL;
    }

    QModbusDataUnit readUnit = QModbusDataUnit(QModbusDataUnit::InputRegisters, reg, number);
    QModbusReply *reply = m_modbusDevice->sendReadRequest(readUnit, devid);

    qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] txWA devid = %3, reg = %4, value =").\
                        arg(m_comPort).arg(m_baudrate).\
                        arg(devid).\
                        arg(reg) << readUnit.values();

    return reply;
}

GeconDevice::GeconDevice(QObject *parent)
    : QObject(parent)
    , d_ptr(new GeconDevicePrivate(this))
{
    Q_D(GeconDevice);
}

GeconDevice::GeconDevice(const QString &comPort, QObject *parent, int baudrate)
    : QObject(parent)
    , d_ptr(new GeconDevicePrivate(comPort, baudrate, this))
{
    Q_D(GeconDevice);
}

GeconDevice::~GeconDevice()
{
    //delete d_ptr;
}

GeconDevice::GeconDevice(GeconDevicePrivate &dd, QObject *parent)
    : d_ptr(&dd)
{

}

const QString &GeconDevice::comPort() const
{
    Q_D(const GeconDevice);
    return d->m_comPort;
}

int GeconDevice::baudrate() const
{
    Q_D(const GeconDevice);
    return d->m_baudrate;
}

bool GeconDevice::connectDevice()
{
    Q_D(GeconDevice);

    return d->m_modbusDevice->connectDevice();
}

bool GeconDevice::connectToDevice(const QString &address, int port)
{
    Q_D(GeconDevice);

    return d->connectToDevice(address, port);
}

bool GeconDevice::isConnected()
{
    Q_D(GeconDevice);

    return (d->m_state == QModbusDevice::ConnectedState);
}

int GeconDevice::devReadRegistersAsync(int devid, int reg, int number)
{
    Q_D(GeconDevice);

    QModbusReply *reply = d->devReadRegistersAsync(devid, reg, number);
    if (!reply) {
        return -1;
    }

    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        double value;
        QByteArray replyData = reply->rawResult().data();

        qCDebug(APP_GECON) << QObject::tr("dev[%1:%2] rxWA devid = %3, reg = %4, adu = %5").\
                            arg(d->m_comPort).arg(d->m_baudrate).\
                            arg(devid).\
                            arg(reg).\
                            arg(replyData.toHex(' ').constData());

        if (reply->error() != QModbusDevice::NoError) {
            qCWarning(APP_GECON) << "Reply error: " << reply->errorString();
            delete reply;
            return;
        }

        const QModbusDataUnit unit = reply->result();
        for (uint i = 0; i < unit.valueCount(); i++) {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i).
                    arg(QString::number(unit.value(i), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            qCDebug(APP_GECON) << entry;
        }

        //emit responseValueGet(addressPair, devid, reg, value);

        reply->deleteLater();
    });

    return 0;
}
