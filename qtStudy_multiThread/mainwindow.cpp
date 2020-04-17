#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "tracemodel.h"
#include "xcommdefine.h"

#include <QSortFilterProxyModel>
#include <QFileDialog>
#include <QThread>
#include <QDebug>

void MainWindow::init()
{
    m_model = new TraceModel(this);

    // setup filter model
    m_sortModel = new QSortFilterProxyModel(this);
    m_sortModel->setSourceModel(m_model);
    m_sortModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    m_sortModel->setFilterKeyColumn(0);
    ui->tblFrame->setModel(m_sortModel);

    ui->tblFrame->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tblFrame, &QWidget::customContextMenuRequested, this, &MainWindow::tvCustomContextMenu);

    QObject::connect(ui->cbDataFilter->lineEdit(), &QLineEdit::returnPressed, this, &MainWindow::tvDataFilter);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

    qRegisterMetaType<BusFrame>("BusFrame");
    startWorker();
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
    QObject::connect(m_worker, &Worker::frameCatched, m_model, &TraceModel::frameCatched);
    QObject::connect(this, &MainWindow::loadFile, m_worker, &Worker::handle_loadFile);

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

void MainWindow::on_pbLoad_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open"), QString(), tr("Log Files (*.bin);;All Files (*.*)"));

    if (fileName.isEmpty())
        return;

    ui->leFilePath->setText(fileName);

    emit loadFile(fileName);
}

void MainWindow::tvDataFilter()
{
    m_sortModel->setFilterRegExp(ui->cbDataFilter->currentText());
    m_sortModel->setFilterKeyColumn(ui->cbColumn->currentIndex());
}
