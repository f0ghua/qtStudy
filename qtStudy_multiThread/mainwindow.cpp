#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "windows.h"
#include "QAppLogging.h"

#include <QTimer>
#include <QSettings>
#include <QDebug>

#ifdef THREAD_ENABLE
#include <QThread>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_settings = new QSettings("./config.ini", QSettings::IniFormat, this);
    m_settings->setIniCodec("UTF-8");

    m_timerClick = new QTimer(this);
    m_timerClick->setInterval(1000);
    connect(m_timerClick, &QTimer::timeout, this, &MainWindow::handleClickTimeout);

    startWork();

#ifdef THREAD_ENABLE
    startWorker();
#endif
}

MainWindow::~MainWindow()
{
#ifdef THREAD_ENABLE
    stopWorker();
#endif
    delete ui;
}

#ifdef THREAD_ENABLE
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
#endif

bool MainWindow::startWork()
{
    const QString targetAppName = "浩方电竞平台";
    QString className = "#32770";
    LPTSTR classNameDialog = (LPTSTR)className.utf16();
    //const TCHAR classNameDialog[] = __TEXT("WeChatMainWndForPC");//
    TCHAR buffer[MAX_PATH];

    m_hMain = NULL;
    while (m_hMain = ::FindWindowEx(0, m_hMain, classNameDialog, NULL)) {
        ::GetWindowText(m_hMain, buffer, MAX_PATH - 1);
        QString appWName = QString::fromWCharArray(buffer);
        if (appWName.contains(targetAppName)) {
            break;
        }
    }

    if (!m_hMain) {
        QLOG_DEBUG() << "No app found";
        return false;
    }

    //HWND hListView;
    //if (hListView = ::GetDlgItem(m_hMain, 0x49A))

    return true;
}

void MainWindow::handleClickTimeout()
{

}
