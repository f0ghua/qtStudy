#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "mmtimer.h"

#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QVector>
#include <QTimer>

#define TIMER_INTERVAL  5
QVector<QDateTime> timeArray;

static VOID CALLBACK MilliSecondProc1(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    QDateTime time = QDateTime::currentDateTime();
    timeArray.append(time);
    qDebug() << "call MilliSecondProc1";
    //QDateTime::currentMSecsSinceEpoch();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startWorker();

    m_TimerMedia.uTimerID = 1;
    m_TimerMedia.uResolution = 5;

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, [&]{
        MilliSecondTimerEnd(m_TimerMedia.uTimerID, &m_TimerMedia.uResolution);
        /*
        for (int i = 0; i < timeArray.count(); i++) {
            qDebug() <<
        }
        */
        qDebug() << timeArray;
    });

    timeArray.reserve(150);

#if 1
    QTimer *cTimer = new QTimer(this);
    cTimer->setTimerType(Qt::PreciseTimer);
    cTimer->setInterval(TIMER_INTERVAL);
    connect(cTimer, &QTimer::timeout, this, [&]{
        QDateTime time = QDateTime::currentDateTime();
        timeArray.append(time);
    });
    cTimer->start();
#else
    MilliSecondTimerStart(m_TimerMedia.uTimerID, TIMER_INTERVAL, m_TimerMedia.uResolution,
                          (LPVOID)&MilliSecondProc1, 0, TRUE);
#endif

    timer->start();
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
