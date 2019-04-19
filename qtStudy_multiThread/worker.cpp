#include "worker.h"
#include "QAppLogging.h"

#include <QTimer>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::run()
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer, &QTimer::timeout, this, &Worker::onTimerTimeout);
    timer->start();

}

void Worker::onTimerTimeout()
{
    QLOG_DEBUG() << "debug message appended";
}
