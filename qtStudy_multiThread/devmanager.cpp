#include "devmanager.h"
#include "eloadn6101.h"

#include <QModbusReply>
#include <QTimer>
#include <QVector>
#include <QDebug>

#define CM_ELOAD_CHANNEL_NUMBER 12
#define CM_ELOAD_NUMBER         2

class DevManagerPrivate : public QObject
{
    Q_DECLARE_PUBLIC(DevManager)
public:
    DevManagerPrivate(DevManager *parent);
    virtual ~DevManagerPrivate();

    void init();
    void addEload(int id, const QString &address, int port);
    void addRelay(int id, const QString &address, int port);
    void addPower(int id, const QString &address, int baudRate);
    void eloadModeInit(int id, int channel);
    void eloadSetScreenPresent(int id);

    DevManager * const q_ptr;
    QVector<EloadN6101 *> m_eloads;
    QMap<QString, int> m_eloadAddrMapping;
    QTimer *m_timer;

public slots:
    void onTimerTimeout();
};

DevManagerPrivate::DevManagerPrivate(DevManager *parent)
    : QObject(parent)
    , q_ptr(parent)
{
    Q_Q(DevManager);

    m_eloads.resize(CM_ELOAD_NUMBER);
    for (int i = 0; i < CM_ELOAD_NUMBER; i++) {
        m_eloads[i] = NULL;
    }
    m_eloadAddrMapping.clear();
}

DevManagerPrivate::~DevManagerPrivate()
{

}

void DevManagerPrivate::init()
{
    Q_Q(DevManager);

    addEload(0, "127.0.0.1", 7000);
    addEload(1, "127.0.0.1", 7001);

    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &DevManagerPrivate::onTimerTimeout);
    m_timer->start();

    emit q->devMgrReady();
}

void DevManagerPrivate::onTimerTimeout()
{
    foreach (EloadN6101 *eload, m_eloads) {
        if (eload && !eload->isConnected()) {
            eload->connectDevice();
        }
    }
}

void DevManagerPrivate::addEload(int id, const QString &address, int port)
{
    Q_Q(DevManager);

    if (m_eloads[id]) {
        delete m_eloads[id];
        m_eloads[id] = NULL;
    }
    m_eloads[id] = new EloadN6101(address, port, this);
    QObject::connect(m_eloads[id], &EloadN6101::responseValueGet, q, &DevManager::eloadRegValueUpdate);
    for (int i = 0; i < CM_ELOAD_CHANNEL_NUMBER; i++) {
        //eloadModeInit(id, i);
    }

    QString addrPair = QString("%1:%2").arg(address).arg(port);
    m_eloadAddrMapping.insert(addrPair, id);
}

void DevManagerPrivate::eloadModeInit(int id, int channel)
{
    if (m_eloads[id] == NULL)
        return;

    m_eloads[id]->setCCModeAsync(channel);
    m_eloads[id]->setConfigedCurrentAsync(channel, 0);
    m_eloads[id]->setFunctionTimeAsync(channel);
    m_eloads[id]->setFunctionOnAsync(channel, true);
}

void DevManagerPrivate::eloadSetScreenPresent(int id)
{
    if (m_eloads[id] == NULL)
        return;

    QByteArray ba = QByteArrayLiteral("\x1b\x11\x00\xa0\x01\x00\x01\x00\x00\x01\x00\x00\x00\xe6\x00\x0a\x0d");
    m_eloads[id]->devWriteRawDataAsync(ba);
}

DevManager::DevManager(QObject *parent)
    : QObject(parent)
    , d_ptr(new DevManagerPrivate(this))
{
    Q_D(DevManager);
}

DevManager::~DevManager()
{

}

void DevManager::run()
{
    Q_D(DevManager);

    d->init();
}

void DevManager::eloadClearAllConfigedCurrent()
{
    Q_D(DevManager);
    for (int id = 0; id < CM_ELOAD_NUMBER; id++) {
        for (int channel = 0; channel < CM_ELOAD_CHANNEL_NUMBER; channel++) {
            eloadSetConfigedCurrent(id, channel, 0);
        }
    }
}

void DevManager::eloadSetConfigedCurrent(int id, int channel, double value)
{
    Q_D(DevManager);

    if (d->m_eloads[id] == NULL)
        return;

    d->m_eloads[id]->setConfigedCurrentAsync(channel, value);
}

DevMgrReply *DevManager::eloadSetConfigedCurrentAsyncEx(int id, int channel, double value)
{
    Q_D(DevManager);

    if (d->m_eloads[id] == NULL)
        return NULL;

    QModbusReply *reply = d->m_eloads[id]->setConfigedCurrentAsyncEx(channel, value);
    if (reply == NULL) {
        return NULL;
    }

    DevMgrReply *devMgrReply = new DevMgrReply();
    QObject::connect(reply, &QModbusReply::finished, this, [=](){
        if (reply->error() != QModbusDevice::NoError) {
            qDebug() << "Reply error: " << reply->errorString();
        }
        emit devMgrReply->finished();
        reply->deleteLater();
    });

    return devMgrReply;
}

void DevManager::eloadGetCurrent(int id, int channel)
{
    Q_D(DevManager);

    if (d->m_eloads[id] == NULL)
        return;

    d->m_eloads[id]->getCurrentAsync(channel);
}

int DevManager::getEloadIdbyAddress(const QString &addressPair)
{
    Q_D(DevManager);

    QMap<QString, int>::const_iterator ci;
    ci = d->m_eloadAddrMapping.find(addressPair);
    if (ci != d->m_eloadAddrMapping.end()) {
        return ci.value();
    }

    return -1;
}
