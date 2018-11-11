#include "itechdevice.h"
#include "itechdevice_p.h"
//#include "utils.h"

#include <QEventLoop>
#include <QLoggingCategory>
#include <QSerialPort>
#include <QByteArray>
#include <QQueue>

Q_LOGGING_CATEGORY(APP_ITECH, "app.itechdevice")
Q_LOGGING_CATEGORY(APP_ITECH_LOW, "app.itechdevice.lowlevel")

struct Settings {
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};

class ITechDevicePrivate : public QObject
{
    Q_DECLARE_PUBLIC(ITechDevice)
public:
    ITechDevicePrivate(QString portName, int baudRate, ITechDevice *parent);
    virtual ~ITechDevicePrivate();

    void initDevice(QString portName, int baudRate);
    void connectToDevice();
    void disConnectDevice();
    void setBaudRate(quint32 baudRate);
    void handleError(QSerialPort::SerialPortError error);


    void openSerialPort();
    void closeSerialPort();

    void writeData(QByteArray &data, ITechDevice::MsgType &type);
    void writeData(QByteArray &data);
    void handleReadyRead();
    void handleCmd(QByteArray &data);

    ITechDevice * const q_ptr;


    Settings m_setting;
    quint32 m_baudRate = 0;
    QString m_portName;
    QByteArray m_rspData;

    enum State {
        Idle,
        Schedule,
        Send,
        Receive,
    } m_state = Idle;

// To support async send!
    void setupSerialPort(QString portName, int baudRate);
    void scheduleNextRequest();
    QSerialPortReply *enqueueRequest(const QSerialPortRequest &request);
    void processQueue();
    bool canMatchRequestAndResponse(const QByteArray &response) const;
    void processQueueElement(const QByteArray &pdu, const QueueElement &element);

    QTimer m_sendTimer;
    QTimer m_responseTimer;
    QTimer m_noreponseTimer;

    QueueElement m_current;
    QByteArray responseBuffer;

    QQueue<QueueElement> m_queue;
    //QQSerialPortSocket *m_socket = nullptr;
    QSerialPort *m_serial = nullptr;
    int mbpaHeaderSize = 7;
    int m_interFrameDelayMilliseconds = 50;
    bool m_isWriteFinished = false;
    int m_responseTimeoutDuration = 300;
    int m_numberOfRetries = 0;


};

ITechDevicePrivate::ITechDevicePrivate(QString portName, int baudRate, ITechDevice *parent)
    :q_ptr(parent)
{
    Q_Q(ITechDevice);
    setupSerialPort(portName, baudRate);
    connectToDevice();
}

ITechDevicePrivate::~ITechDevicePrivate()
{

}

void ITechDevicePrivate::setupSerialPort(QString portName, int baudRate)
{
    m_sendTimer.setSingleShot(true);
    QObject::connect(&m_sendTimer, &QTimer::timeout, this, [this]() { processQueue(); });

    m_responseTimer.setSingleShot(true);
    QObject::connect(&m_responseTimer, &QTimer::timeout, this, [this]() { processQueue(); });

    //for cmd do not need itechdevice to response, use a timer to emit the finish reply
#if 0
    //just use send cmd correctly for cmds which do not need the response
    m_noreponseTimer.setSingleShot(true);
    QObject::connect(&m_noreponseTimer, &QTimer::timeout, this, [this](){
        if(!m_current.reply.isNull())
            m_current.reply->setFinished(true);
    });
#endif

    m_serial = new QSerialPort(this);

    initDevice(portName, baudRate);

    connect(m_serial, &QSerialPort::errorOccurred, this, &ITechDevicePrivate::handleError);

    QObject::connect(m_serial, &QSerialPort::aboutToClose, [this]() {
#ifdef F_NO_DEBUG
       qDebug()  << "(QSerialPort client) Connection closed.";
#endif
       m_sendTimer.stop();
       m_responseTimer.stop();
    });

    QObject::connect(m_serial, &QSerialPort::readyRead, [this](){

        QByteArray responseData = m_serial->readAll();
        if(responseData != QByteArray("\n"))
        {
            responseBuffer += responseData;
            return;
        }
        if (responseBuffer.isEmpty())
            return;
#ifdef F_NO_DEBUG
        qDebug() << "(QSerialPort client) Read Serial ADU: 0x" +
                                            responseBuffer.toHex() + ", " +
                                            responseBuffer.trimmed().toStdString().data();
#endif
        if (!canMatchRequestAndResponse(responseBuffer)) {
            qDebug() << "(QSerialPort client) Cannot match response with open request, "
                "ignoring";
            return;
        }

        if (m_state != State::Receive) {
#ifdef F_NO_DEBUG
            qDebug() << "(QSerialPort client) received packet but m_state is " << m_state;
#endif
            return;
        }

        m_sendTimer.stop();
        m_responseTimer.stop();

        processQueueElement(responseBuffer, m_current);

        m_state = Schedule; // reschedule, even if empty
        QTimer::singleShot(m_interFrameDelayMilliseconds, [this]() { processQueue(); });
    });

    QObject::connect(m_serial, &QIODevice::bytesWritten, this, [this](qint64 bytes) {
        m_current.bytesWritten += bytes;

        if ((m_state == Send) && (!m_current.reply.isNull()) &&
                (m_current.bytesWritten >= m_current.requestPdu.data.size())) {
#ifdef F_NO_DEBUG
            qDebug() << "(QSerialPort client) Send successful:" << m_current.requestPdu.data << "," << m_current.requestPdu.type;
#endif
            m_isWriteFinished = true;
            m_state = Receive;
            m_sendTimer.stop();
            m_responseTimer.start(m_responseTimeoutDuration);

        }
    });
}

void ITechDevicePrivate::scheduleNextRequest()
{
    m_state = Schedule;
    //qDebug() << QObject::tr("m_state = %1, this = %2").arg(m_state).arg((int)this);
    QTimer::singleShot(m_interFrameDelayMilliseconds, [this]() { processQueue(); });
}


QSerialPortReply *ITechDevicePrivate::enqueueRequest(const QSerialPortRequest &request)
{
    auto reply = new QSerialPortReply;
    reply->setMsgType(request.type);
    QueueElement element(reply, request, m_numberOfRetries + 1);
#ifdef F_NO_DEBUG
    qDebug() << "enqueue request.type " << request.type;
    qDebug() << "m_state :" << m_state;
#endif
    m_queue.enqueue(element);

    if (m_state == Idle)
        scheduleNextRequest();
    return reply;
}

void ITechDevicePrivate::processQueue()
{
    Q_ASSERT_X(!m_sendTimer.isActive(), "processQueue", "send timer active");
    Q_ASSERT_X(!m_responseTimer.isActive(), "processQueue", "response timer active");

    auto writeAdu = [this]() {
        m_isWriteFinished = false;
        responseBuffer.clear();
        m_current.bytesWritten = 0;
        m_current.numberOfRetries--;
        m_serial->write(m_current.requestPdu.data);
        if (!m_isWriteFinished) {
            m_sendTimer.start(m_interFrameDelayMilliseconds);
        }
#ifdef F_NO_DEBUG
        qDebug() << "m_current request type" << m_current.requestPdu.type;
        qDebug() << "(QSerialPort client) Sent Serial PDU:" << m_current.requestPdu.data;
#endif
    };

    switch (m_state) {
    case Schedule:
        m_current = QueueElement();
        if (!m_queue.isEmpty()) {
            m_current = m_queue.dequeue();
            if (m_current.reply) {
                m_state = Send;

                QTimer::singleShot(0, [writeAdu]() { writeAdu(); });
            } else {
                QTimer::singleShot(0, [this]() { processQueue(); });
            }
        } else {
            m_state = Idle;
        }
        break;

    case Send:
        // send timeout will always happen
        if (m_current.reply.isNull()) {
            scheduleNextRequest();
        } else if (m_current.bytesWritten < m_current.requestPdu.data.size()) {
#ifdef F_NO_DEBUG
            qDebug() << "(QSerialPort client) Send failed:" << m_current.requestPdu.data;
#endif
            if (m_current.numberOfRetries <= 0) {
                if (m_current.reply) {
                }
                m_current = QueueElement();
                scheduleNextRequest();
            } else {
                m_serial->flush();
                QTimer::singleShot(m_interFrameDelayMilliseconds, [writeAdu]() { writeAdu(); });
            }
        } else {
#ifdef F_NO_DEBUG
            qDebug() << "(QSerialPort client) Send successful:" << m_current.requestPdu.data << "," << m_current.requestPdu.type;
#endif
            m_state = Receive;
            m_responseTimer.start(m_responseTimeoutDuration);
        }

        break;

    case Receive:
        // receive timeout will only happen after successful send
#ifdef F_NO_DEBUG
        qDebug() << "(QSerialPort client) Receive timeout:" << m_current.requestPdu.data;
#endif
        if (m_current.reply.isNull()) {
            scheduleNextRequest();
        } else if (m_current.numberOfRetries <= 0) {
            if (m_current.reply) {

            }
            scheduleNextRequest();
        } else {
            m_state = Send;
            m_serial->flush();
            QTimer::singleShot(m_interFrameDelayMilliseconds, [writeAdu]() { writeAdu(); });
        }
        break;

    case Idle:
    default:
        Q_ASSERT_X(false, "processQueue", QByteArray("unexpected state: ").append(m_state));
        break;
    }
}

bool ITechDevicePrivate::canMatchRequestAndResponse(const QByteArray &response) const
{
    //can not check too much for the response far now
    if (m_current.reply.isNull())
        return false;   // reply deleted    

    return true;
}


void ITechDevicePrivate::processQueueElement(const QByteArray &pdu,
                                               const QueueElement &element)
{
    bool ok;
    double value = pdu.toDouble(&ok);

    if(ok && (element.requestPdu.type != ITechDevice::MsgType::OTHERS)){
        element.reply->setReply(value);
    }else{
        QString str(pdu);
        element.reply->m_info = str;
    }
    element.reply->setFinished(true);
}


void ITechDevicePrivate::setBaudRate(quint32 baudRate)
{
    switch(baudRate){
        case 1200:
            m_setting.baudRate = QSerialPort::Baud1200;
            break;
        case 2400:
            m_setting.baudRate = QSerialPort::Baud2400;
            break;
        case 4800:
            m_setting.baudRate = QSerialPort::Baud4800;
            break;
        case 9600:
            m_setting.baudRate = QSerialPort::Baud9600;
            break;
        case 19200:
            m_setting.baudRate = QSerialPort::Baud19200;
            break;
        case 38400:
            m_setting.baudRate = QSerialPort::Baud38400;
            break;
        case 57600:
            m_setting.baudRate = QSerialPort::Baud57600;
            break;
        case 115200:
            m_setting.baudRate = QSerialPort::Baud115200;
            break;
        default:
            m_setting.baudRate = QSerialPort::Baud9600;
    }
}
void ITechDevicePrivate::initDevice(QString portName, int baudRate)
{
    Q_Q(ITechDevice);
    //m_serial = new QSerialPort(this);

    //
    //connect(m_serial, &QSerialPort::readyRead, this, &ITechDevicePrivate::handleReadyRead);

    m_setting.name = portName;
    m_setting.dataBits = QSerialPort::Data8;
    m_setting.parity = QSerialPort::NoParity;
    m_setting.stopBits = QSerialPort::OneStop;
    m_setting.flowControl = QSerialPort::NoFlowControl;
    setBaudRate(baudRate);
}

void ITechDevicePrivate::connectToDevice()
{
    openSerialPort();
}

void ITechDevicePrivate::disConnectDevice()
{
    closeSerialPort();
}

void ITechDevicePrivate::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
#ifdef F_NO_DEBUG
        qDebug() << tr("Critical Error") << m_serial->errorString();
#endif
        closeSerialPort();
    }
}

void ITechDevicePrivate::handleReadyRead()
{
    QByteArray data = m_serial->readAll();
    handleCmd(data);
}

void ITechDevicePrivate::handleCmd(QByteArray &data)
{
    Q_Q(ITechDevice);
    QByteArray ba("\n");

    if(data != ba) {
        m_rspData.append(data);
    }else {
        //emit q->sigResponseInfoGet(m_rspData);
        m_rspData.clear();
    }
}

void ITechDevicePrivate::closeSerialPort()
{
    if(m_serial->isOpen())
        m_serial->close();
#ifdef F_NO_DEBUG
    qDebug() << "close the serialport";
#endif
}

void ITechDevicePrivate::writeData(QByteArray &data, ITechDevice::MsgType &type)
{
    Q_Q(ITechDevice);
    //m_serial->write(data);
    //1. build request
    //2. enqueue request
    //3. connect finish operation

    QSerialPortRequest request;
    request.data = data;
    request.type = type;

    auto *reply = enqueueRequest(request);
    if(!reply->isFinished()){

        connect(reply, &QSerialPortReply::finished, this, [this, reply, q](){
            if(reply->m_type == ITechDevice::MsgType::CURRENT || reply->m_type == ITechDevice::MsgType::VOLTAGE){
                emit q->reponseValue(reply->m_reply, reply->m_type);
            }else if(reply->m_type == ITechDevice::MsgType::OTHERS){
                emit q->reponseInfo(reply->m_info, reply->m_type);

            }
            delete reply;
        });
    }
}

void ITechDevicePrivate::writeData(QByteArray &data)
{
    m_serial->write(data);
}

void ITechDevicePrivate::openSerialPort()
{

    m_serial->setPortName(m_setting.name);
    m_serial->setBaudRate(m_setting.baudRate);
    m_serial->setDataBits(m_setting.dataBits);
    m_serial->setParity(m_setting.parity);
    m_serial->setStopBits(m_setting.stopBits);
    m_serial->setFlowControl(m_setting.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
#ifdef F_NO_DEBUG
        qDebug() << tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(m_setting.name).arg(m_setting.baudRate).arg(m_setting.dataBits)
                          .arg(m_setting.parity).arg(m_setting.stopBits).arg(m_setting.flowControl);
#endif
    } else {
        //QMessageBox::critical(this, tr("Error"), m_serial->errorString());
#ifdef F_NO_DEBUG
        qDebug() << tr("Error") << m_serial->errorString();
        qDebug() << tr("Open error");
#endif
    }
}



ITechDevice::ITechDevice(QString portName, int baudRate, QObject *parent)
    : QObject(parent)
    , d_ptr(new ITechDevicePrivate(portName, baudRate, this))
{
    Q_D(ITechDevice);
}

ITechDevice::~ITechDevice()
{
    delete d_ptr;
}

ITechDevice::ITechDevice(ITechDevicePrivate &dd, QObject *parent)
    : d_ptr(&dd)
{

}

void ITechDevice::connectToDevice()
{
    Q_D(ITechDevice);
    d->connectToDevice();
}

void ITechDevice::disConnectDevice()
{
    Q_D(ITechDevice);
    d->disConnectDevice();
}

void ITechDevice::devSendCmd(QByteArray &cmd, ITechDevice::MsgType type)
{
    Q_D(ITechDevice);
    d->writeData(cmd, type);
}
void ITechDevice::devSendCmd(QByteArray &cmd)
{
    Q_D(ITechDevice);
    d->writeData(cmd);
}

bool ITechDevice::isConnected()
{
    Q_D(ITechDevice);
    return d->m_serial->isOpen();
}
