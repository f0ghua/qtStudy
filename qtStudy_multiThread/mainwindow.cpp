#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include "log4qt/consoleappender.h"
#include "log4qt/fileappender.h"
#include "log4qt/rollingfileappender.h"
#include "log4qt/logger.h"
#include "log4qt/ttcclayout.h"
#include "log4qt/logmanager.h"

#include <QThread>
#include <QDebug>
#include <QPainter>

#include <bitset>

template<int N>
class SimpleIdStorage {
public:
    std::bitset<N> ids;

    bool isIdExist()
    {
        return !ids.all();
    }

    int getId()
    {
        if (!isIdExist()) {
            return -1;
        }

        for (int i = 0; i < N; ++i) {
            if (!ids.test(static_cast<size_t>(i))) {
                ids.set(static_cast<size_t>(i));
                return i;
            }
        }
        return -1;
    }

    void releaseId(int i)
    {
        ids.reset(static_cast<size_t>(i));
    }
};


static quint16 getStartBitByPosition(quint16 bitPosition,
                                        bool isHighLowByteOrder,
                                        quint16 bitSize)
{
    quint16 startBit = 0;

    if (isHighLowByteOrder) {
        // bitPostion is the highest bit(at lower byte) of the signal
        quint16 lowerByteBits = (bitPosition % 8 + 1);
        bool isMultiBytes = (lowerByteBits < bitSize) ? true : false;
        if (!isMultiBytes) {
            startBit = bitPosition - bitSize + 1;
        } else {
            // get next byte highest bit position
            quint16 netxByteMsbPostion = ((bitPosition+1)/8 + 2)*8 - 1;
            quint16 leftBits = static_cast<quint16>(bitSize) - lowerByteBits;
            while (leftBits > 8) {
                netxByteMsbPostion += 8;
                leftBits -= 8;
            }

            startBit = netxByteMsbPostion - leftBits + 1;
        }
    } else {
        startBit = bitPosition;
    }

    //qDebug() << "m_startBit = " << m_startBit;

    return startBit;
}

int roundDown(int i, int r)
{
    int remainder = i % r;
    int rounded = (i < 5) ? i : (i - remainder);

    return rounded;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //startWorker();

    //setWindowFlags(Qt::FramelessWindowHint);

    ui->qwtDial->setMaxValue(300);
    ui->qwtDial->setValue(210);

    ui->statusBar->hide();
    //ui->qwtDial->setBackground(Qt::red);

    // Create a layout
    auto logger = Log4Qt::Logger::rootLogger();
    auto *layout = new Log4Qt::TTCCLayout();
    layout->setName(QStringLiteral("My Layout"));
    layout->activateOptions();
    // Create a console appender
    Log4Qt::ConsoleAppender *consoleAppender = new Log4Qt::ConsoleAppender(layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
    consoleAppender->setName(QStringLiteral("My Appender"));
    consoleAppender->activateOptions();
    // Add appender on root logger
    logger->addAppender(consoleAppender);
    // Create a file appender
//    Log4Qt::FileAppender *fileAppender = new Log4Qt::FileAppender(layout, QCoreApplication::applicationDirPath() + "/basic.log", true);
//    fileAppender->setName(QStringLiteral("My file appender"));
//    fileAppender->activateOptions();
//    // Add appender on root logger
//    logger->addAppender(fileAppender);

    // Create a file appender
    Log4Qt::RollingFileAppender *fileAppender = new Log4Qt::RollingFileAppender(layout, QCoreApplication::applicationDirPath() + "/basic.log", true);
    fileAppender->setName(QStringLiteral("My file appender"));
    fileAppender->setMaxFileSize("10kb");
    fileAppender->setMaxBackupIndex(3);
    fileAppender->activateOptions();
    // Add appender on root logger
    logger->addAppender(fileAppender);

    // Set level to info
    logger->setLevel(Log4Qt::Level::ALL_INT);
    // Enable handling of Qt messages
    Log4Qt::LogManager::setHandleQtMessages(true);

    for (int i = 0; i < 10000; i++) {
        qDebug() << roundDown(i, 5);
    }

}

MainWindow::~MainWindow()
{
    //stopWorker();
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd(":/new/prefix1/bk");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QMainWindow::resizeEvent(evt); //call base implementation
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
