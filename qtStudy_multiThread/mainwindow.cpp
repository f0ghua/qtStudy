#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //startWorker();
}

MainWindow::~MainWindow()
{
    //stopWorker();
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

void MainWindow::on_pushButton_2_clicked()
{
    m_socket = new QUdpSocket(this);
    connect(m_socket, &QUdpSocket::readyRead, this, [&]{
        qDebug() << "ready Read received";
        while (m_socket->hasPendingDatagrams()) {

            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());

            m_socket->readDatagram(datagram.data(), datagram.size(),
                                   &m_sender, &m_senderPort);
//            m_socket->writeDatagram(datagram.data(), datagram.size(),
//                                    m_sender, m_senderPort);
            qDebug() << "client ready Read received";

        }
    });

    //m_socket->bind(9998);

    QByteArray ba = QByteArrayLiteral("\x11\x22");
    m_socket->writeDatagram(ba, ba.size(), QHostAddress("127.0.0.1"), 9999);


}

void MainWindow::on_pushButton_clicked()
{
    m_socket = new QUdpSocket(this);
    m_socket->bind(9999);
    connect(m_socket, &QUdpSocket::readyRead, this, [&]{
        while (m_socket->hasPendingDatagrams()) {

            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());

            m_socket->readDatagram(datagram.data(), datagram.size(),
                                   &m_sender, &m_senderPort);
            m_socket->writeDatagram(datagram.data(), datagram.size(),
                                    m_sender, m_senderPort);
            qDebug() << "server ready Read received";

        }
    });


}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray ba = QByteArrayLiteral("\x33\x44");
    m_socket->writeDatagram(ba.data(), ba.size(),
                            m_sender, m_senderPort);
}
