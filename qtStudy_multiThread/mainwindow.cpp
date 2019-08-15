#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "canbittiming.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leBaudrate->setText(QString::number(500000));
    ui->leSamplePoint->setText(QString::number(875));
    //flexcan_bitiming_print();



    //startWorker();
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

void MainWindow::on_pbCalculate_clicked()
{
    QString name = ui->cbDevName->currentText();
    quint32 baudrate = ui->leBaudrate->text().toUInt();
    quint32 spt = ui->leSamplePoint->text().toUInt();

    CANBitTimingCal ctc;
    ctc.calcBitTimingStd(name, baudrate, spt);
}
