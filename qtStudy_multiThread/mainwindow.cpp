#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "DBC.h"

#include <QThread>
#include <QDebug>

using namespace Vector::DBC;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //startWorker();
    {
        File *dbFile = new File();

        QString dbName = "1.xml";
        if ((int)dbFile->load(dbName) != 0) {
            return;
        }

        NetworkHandle *nh = dbFile->netHandle();
        nh->dumpMessages();
    }
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
