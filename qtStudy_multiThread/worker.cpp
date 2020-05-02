#include "worker.h"

#include <QCoreApplication>
#include <QThread>
#include <QDebug>

Worker::Worker(QObject *parent)
    : QObject(parent)
    , m_isRunning(true)
{

}

void Worker::run()
{
    return;
}

void Worker::onWorkStop()
{
    m_isRunning = false;
}

void Worker::onWorkStart()
{
    qDebug() << "onWorkStart enter";

    while (m_isRunning) {
        QThread::msleep(1);
        QCoreApplication::processEvents();
    }

    qDebug() << "onWorkStart exit";

}
