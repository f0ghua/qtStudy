#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "ftusbbackend.h"
#include "canconnfactory.h"
#include "ienginebackendhelper.h"
#include "QAppLogging.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startWorker();

    initWidgets();
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
    QObject::connect(this, &MainWindow::workStop, m_worker, &Worker::onWorkStop);
    QObject::connect(m_worker, &Worker::msgDump, this, &MainWindow::onMsgDump);

    m_workThread->start(QThread::HighPriority);
    qDebug() << "Worker thread started.";
}

void MainWindow::stopWorker()
{
    emit workStop();

    if(m_workThread && (!m_workThread->isFinished())) {
        m_workThread->quit();
        if(!m_workThread->wait()) {
            qDebug() << "can't stop thread";
        }
        qDebug() << "Worker thread finished.";
    }
}

void MainWindow::onMsgDump(const QString &msg)
{
    ui->plainTextEdit->appendPlainText(msg);
}

void MainWindow::initWidgets()
{
#ifdef USE_FTUSBBACKEND
    QStringList devLists = FTUSBBackend::getDeviceList(true);
    int devNumber = devLists.at(0).toInt();

    if ((devNumber + 1) != devLists.size())
        return;

    for (int i = 0; i < devNumber; i++) {
        ui->cbDevices->addItem(devLists.at(i+1));
    }
#else
    IEngineBackEndHelper ie;
    QStringList devLists = ie.availablePorts();
    for (int i = 0; i < devLists.size(); i++) {
        ui->cbDevices->addItem(devLists.at(i));
    }
#endif

    ui->leWaitLoop->setText(QString::number(WKER_WAITLOOP));
    ui->comboBox->setCurrentIndex(0);
    ui->cbLogDest->setCurrentIndex(2);
}

void MainWindow::on_pbConnect_clicked()
{
    QMetaObject::invokeMethod(
                m_worker, "createConnection",
                Qt::BlockingQueuedConnection,
                Q_ARG(const QString&, ui->cbDevices->currentText())
                );
}

void MainWindow::on_pbStart_clicked()
{
    QMetaObject::invokeMethod(
                m_worker, "startBenchmark",
                Qt::QueuedConnection
                );
}

void MainWindow::on_pbStop_clicked()
{
    QMetaObject::invokeMethod(
                m_worker, "stopBenchmark",
                Qt::QueuedConnection
                );
}

void MainWindow::on_leWaitLoop_editingFinished()
{
    QMetaObject::invokeMethod(
                m_worker, "setWaitLoop",
                Qt::BlockingQueuedConnection,
                Q_ARG(quint32, ui->leWaitLoop->text().toUInt())
                );
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QAppLogging::instance()->setFilterRulesByLevel(QAppLogging::LogLevel(index));
}

void MainWindow::on_cbLogDest_currentIndexChanged(int index)
{
    QAppLogging::instance()->setOutputDest(QAppLogging::LogDest(index));
}
