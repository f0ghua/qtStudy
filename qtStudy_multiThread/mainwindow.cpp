#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "QAppLogging.h"
#include "windows.h"

#include <QThread>
#include <QDebug>
#include <QElapsedTimer>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_gv = new GblVar();
    startWorker();

    m_displayTimer = new QTimer(this);
    m_displayTimer->setInterval(100);
    connect(m_displayTimer, &QTimer::timeout, this, &MainWindow::handleDisplayTimeout);

    qDebug() << QElapsedTimer::clockType();
}

MainWindow::~MainWindow()
{
    stopWorker();
    delete ui;
}

void MainWindow::startWorker()
{
    m_workThread = new QThread();
    m_worker = new Worker(m_gv);
    m_worker->moveToThread(m_workThread);
    QObject::connect(m_workThread, &QThread::started, m_worker, &Worker::run);
    QObject::connect(m_workThread, &QThread::finished, m_worker, &Worker::deleteLater);
    QObject::connect(m_workThread, &QThread::finished, m_workThread, &QThread::deleteLater);
    //QObject::connect(this, &MainWindow::workStop, m_worker, &Worker::onWorkStop);

    //m_workThread->start(QThread::HighPriority);
    m_workThread->start(QThread::TimeCriticalPriority);
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

void MainWindow::handleDisplayTimeout()
{
    if (!m_workThread->isRunning())
        return;

    QString s;
    QTextStream ts(&s);
    ts.setFieldWidth(10);
    ts.setRealNumberPrecision(3);
    ts.setRealNumberNotation(QTextStream::FixedNotation);
    ts << m_gv->m_actualRate;
    //ui.->setText(s);

    ui->pteOutput->clear();
    s.clear();
    ts << "Ms" << "Count" << "%" << endl;
    ui->pteOutput->insertPlainText(s);

    quint64 total = 0;
    for (int i = 0; i < HMAX; i++) {
        total += m_gv->m_hSec[i];
    }
    if (total <= 0) total = 1;

    for (int i = 0; i < HMAX; i++) {
        double t = i;
        quint64 c = m_gv->m_hSec[i];
        //if (i == HMAX-1) t = rtThread.m_maxTime;

        if (c > 0) {
            s.clear();
            ts << t << c << c*100.0/total;
            if (i==HMAX-1) ts << " max";
            ts << endl;
            ui->pteOutput->insertPlainText(s);
        }
    }
    ui->pteOutput->moveCursor(QTextCursor::End);
}

void MainWindow::on_pbStart_clicked()
{
    ::SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

    m_gv->m_clockRate = ui->sbClockRate->value();
    QMetaObject::invokeMethod(m_worker, "startTimer", Qt::QueuedConnection);
    if (m_gv->m_clockMode == GblVar::CLOCKMODE_QTIMER) {
        m_displayTimer->start();
    }
}

void MainWindow::on_pbStop_clicked()
{
    if (m_gv->m_clockMode == GblVar::CLOCKMODE_QTIMER) {
        m_displayTimer->stop();
    }
    QMetaObject::invokeMethod(m_worker, "stopTimer", Qt::QueuedConnection);
}
