#include "worker.h"
#include <QTime>
#include <QCoreApplication>

static void msleep(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);

    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::run()
{
    return;

    while(true) {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int N = qrand()%10000;
        for (int i = 0; i < N; i++);
        msleep(100);
    }
}
