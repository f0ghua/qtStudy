#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startWorker();

    QTimer *timer = new QTimer(this);
    timer->setInterval(100);
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    timer->start();

    QTimer *timer2 = new QTimer(this);
    timer2->setInterval(100);
    timer2->setTimerType(Qt::PreciseTimer);
    connect(timer2, &QTimer::timeout, this, &MainWindow::onTimerTimeout2);
    timer2->start();
}

MainWindow::~MainWindow()
{
    stopWorker();
    delete ui;
}

void MainWindow::startWorker()
{
    m_workThread = new QThread();
    m_worker = new Worker();
    m_worker->moveToThread(m_workThread);
    QObject::connect(m_workThread, &QThread::started, m_worker, &Worker::run);
    QObject::connect(m_workThread, &QThread::finished, m_worker, &Worker::deleteLater);
    QObject::connect(m_workThread, &QThread::finished, m_workThread, &QThread::deleteLater);
    //QObject::connect(this, &MainWindow::workStop, m_worker, &Worker::onWorkStop);

    m_workThread->start(QThread::HighPriority);
    qDebug() << "Worker thread started.";
}

void MainWindow::stopWorker()
{
    //emit workStop();

    if(m_workThread && (!m_workThread->isFinished())) {
        m_workThread->quit();
        if(!m_workThread->wait()) {
            qDebug() << "can't stop thread";
        }
        qDebug() << "Worker thread finished.";
    }
}

void MainWindow::onTimerTimeout()
{
    qDebug() << "timer tick count = " << m_timerTickCount << ", elTime = " << m_elapsedTimer.elapsed();
    if (m_timerTickCount == 0) {
        m_elapsedTimer.start();
    }

    m_timerTickCount++;
}

void MainWindow::onTimerTimeout2()
{
    for (int i = 0; i < 10000000; i++);
}
