#include "worker.h"
#include "devmanager.h"

#include <QModbusReply>
#include <QEventLoop>
#include <QDebug>

Worker::Worker(DevManager *devMgr, QObject *parent)
    : QObject(parent)
    , m_devMgr(devMgr)
{
    //qRegisterMetaType<DevMgrReply>();
    //qRegisterMetaType<DevMgrReply *>();
    //qRegisterMetaType<QModbusReply *>("QModbusReply *&");
}

void Worker::run()
{
    for (int i = 0; i < 12; i++) {
        //el_setConfigedCurrentBlock(0, i, 2);
    }

    for (int i = 0; i < 2; i++) {
        rl_getAllStatesBlock(i);
    }
}

int Worker::el_setConfigedCurrentBlock(int id, int channel, double value)
{
    DevMgrReply *reply;
    QMetaObject::invokeMethod(m_devMgr, "eloadSetConfigedCurrentAsyncEx",
                              Qt::BlockingQueuedConnection,
                              Q_RETURN_ARG(DevMgrReply *, reply),
                              Q_ARG(int, id),
                              Q_ARG(int, channel),
                              Q_ARG(double, value));

    QEventLoop loop;
    auto connection = QObject::connect(reply, &DevMgrReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    reply->deleteLater();
    return 0;
}

int Worker::rl_getAllStatesBlock(int id)
{
    DevMgrReply *reply;
    QMetaObject::invokeMethod(m_devMgr, "relayGetStatesEx",
                              Qt::BlockingQueuedConnection,
                              Q_RETURN_ARG(DevMgrReply *, reply),
                              Q_ARG(int, id));

    QEventLoop loop;
    auto connection = QObject::connect(reply, &DevMgrReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    QVector<double> values = reply->values();
    reply->deleteLater();

    return 0;
}

void inline Worker::eloadSetConfigedCurrent(int id, int channel, double value)
{
    qDebug() << QObject::tr("set eload current: id %1, channel %2 value %3").\
            arg(id).arg(channel).arg(value);

    QMetaObject::invokeMethod(m_devMgr, "eloadSetConfigedCurrent",
                              Qt::QueuedConnection,
                              Q_ARG(int, id),
                              Q_ARG(int, channel),
                              Q_ARG(double, value));
}

void inline Worker::eloadGetCurrent(int id, int channel)
{
    QMetaObject::invokeMethod(m_devMgr, "eloadGetCurrent",
                              Qt::QueuedConnection,
                              Q_ARG(int, id),
                              Q_ARG(int, channel));
}
