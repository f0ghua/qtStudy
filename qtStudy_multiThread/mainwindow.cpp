#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFile>
#include <QFileInfo>
#include <QDir>

namespace {
// A header consists with following parts:
//  tag_magic+{tag_spliter+info}{0~n}+tag_end
const char XFILE_TAG_MAGICWORD[] = "@!@!";
const char XFILE_TAG_ENDCHR = '%';
const char XFILE_TAG_SPLITCHR = '#';
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    startWorker();

    ui->menuBar->hide();
    setWindowFlags(Qt::WindowStaysOnTopHint );
    this->setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
//    stopWorker();
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

bool MainWindow::extractAttachedFile(const QString &filePath)
{
    QFile inputFile(filePath);
    if (!inputFile.open(QIODevice::ReadOnly)) {
        return false;
    }
    QByteArray baInput = inputFile.readAll();
    inputFile.close();

    QString outputFileName = "default.tgz";
    int tagStart = baInput.indexOf(XFILE_TAG_MAGICWORD);
    if (tagStart == -1) {
        return false;
    }
    int tagEnd = baInput.indexOf(XFILE_TAG_ENDCHR, tagStart+1);
    QByteArray baTag = baInput.mid(tagStart, tagEnd - tagStart); // exclude the end tag char
    QString tagStr = QString::fromStdString(baTag.toStdString());
    QStringList sl = tagStr.split(XFILE_TAG_SPLITCHR);
    if (sl.size() > 1) {
        outputFileName = sl.at(1);
    }

    int outputFileStart = tagEnd + 1;
    QByteArray baOutput = baInput.mid(outputFileStart);

    QFileInfo fi(filePath);
    QString outputFilePath = fi.absoluteDir().absoluteFilePath(outputFileName);
    qDebug() << tr("output file = %1").arg(outputFilePath);
    QFile outputFile(outputFilePath);
    if (!outputFile.open(QIODevice::WriteOnly|QIODevice::Truncate)) {
        return false;
    }
    outputFile.write(baOutput.data(), baOutput.size());
    outputFile.close();

    return true;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())return ;
    QString fileName = urls.first().toLocalFile();
    if(fileName.isEmpty())return ;
    qDebug() << tr("drop file = %1").arg(fileName);

    extractAttachedFile(fileName);
}
