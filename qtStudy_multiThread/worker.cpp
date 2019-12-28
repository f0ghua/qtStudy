#include "worker.h"

#include <QTime>
#include <QTimer>

Worker::Worker(QObject *parent) : QObject(parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    qRegisterMetaType<Message>("Message");
}

static int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

static const int s_dataLenArray[] = {
    16, 64, 8, 48
};

void Worker::run()
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, [&](){
        Message msg;
        msg.id = 123;
        int len = s_dataLenArray[randInt(0, 3)];
        QByteArray ba(len, 0);
        msg.data = ba;

        emit sendMessage(msg);
    });
    timer->start();

}
