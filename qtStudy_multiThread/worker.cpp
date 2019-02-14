#include "worker.h"
#include "QAppLogging.h"

#include <QTimer>

Worker::Worker(QObject *parent) : QObject(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Worker::handleTimeout);
    timer->start();
}

void Worker::run()
{

}

void Worker::handleTimeout()
{
    QLOG_TRACE() << "trace";
    QLOG_DEBUG() << "debug";
    QLOG_INFO() << "info";
    QLOG_WARNING() << "warning";
    QLOG_ERROR() << "error";
}
