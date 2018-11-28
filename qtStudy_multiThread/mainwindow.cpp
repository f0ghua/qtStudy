#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "devmanager.h"

#include <QThread>
#include <QDebug>
#include <QLoggingCategory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLoggingCategory::setFilterRules(
                QStringLiteral(
                    "qt.modbus* = true\n"
                    "app.* = true\n"
                    )
                );

    startDevMgr();
    startWorker();
}

MainWindow::~MainWindow()
{
    stopDevMgr();
    stopWorker();
    delete ui;
}

void MainWindow::startWorker()
{
    m_workThread = new QThread();
    m_worker = new Worker(m_devMgr);
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

void MainWindow::startDevMgr()
{
    m_devMgrThread = new QThread();
    m_devMgr = new DevManager();
    m_devMgr->moveToThread(m_devMgrThread);
    QObject::connect(m_devMgrThread, &QThread::started, m_devMgr, &DevManager::run);
    QObject::connect(m_devMgrThread, &QThread::finished, m_devMgr, &DevManager::deleteLater);
    QObject::connect(m_devMgrThread, &QThread::finished, m_devMgrThread, &QThread::deleteLater);

    m_devMgrThread->start();
    qDebug() << "DevManager thread started.";
}

void MainWindow::stopDevMgr()
{
    if(m_devMgrThread && (!m_devMgrThread->isFinished())) {
        m_devMgrThread->quit();
        if(!m_devMgrThread->wait()) {
            qDebug() << "can't stop thread";
        }
        qDebug() << "DevManager thread finished.";
    }
}

int MainWindow::rl_getAllStatesBlock(int id, QVector<double> &values)
{
    int ret = 0;
    DevMgrReply *reply;
    QMetaObject::invokeMethod(m_devMgr, "relayGetStatesEx",
                              Qt::BlockingQueuedConnection,
                              Q_RETURN_ARG(DevMgrReply *, reply),
                              Q_ARG(int, id));

    QEventLoop loop;
    auto connection = QObject::connect(reply, &DevMgrReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(connection);

    if (reply->isError())
        ret = -1;

    values = reply->values();
    reply->deleteLater();

    return ret;
}

void MainWindow::on_pbRlGetStates_clicked()
{
    QVector<double> values;
    rl_getAllStatesBlock(0, values);
    QString statesStr;
    for (int i = 0; i < values.size(); i++) {
        int v = values.at(i);
        statesStr += QString("%1:%2, ").arg(i+1).arg(v);
    }
    ui->plainTextEdit->appendPlainText(statesStr);

}
