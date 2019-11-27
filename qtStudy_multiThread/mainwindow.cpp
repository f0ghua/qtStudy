#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QFileDialog>

LSTATUS MainWindow::writeBWRegKeys(QString path)
{
    const QString subKey = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers\\";
    const QString keyValue = "~ DWM8And16BitMitigation Layer_ForceDirectDrawEmulation";
    const LPBYTE lpData = (LPBYTE)keyValue.toStdString().data();

    HKEY hKey;
    DWORD dwDisposition;
    LSTATUS rc = 0;

    qDebug() << keyValue.size();

    rc = RegCreateKeyEx(HKEY_CURRENT_USER, (LPTSTR)subKey.utf16(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, &dwDisposition);
    if (rc)
        return rc;

    const QString bwPath = QDir::toNativeSeparators(path);
    //LPTSTR lpValueName = (LPTSTR)bwPath.utf16();
    LPCSTR lpValueName = (LPCSTR)bwPath.toStdString().data();
    rc = RegSetValueExA(hKey, lpValueName, 0, REG_SZ, (LPBYTE)lpData, keyValue.size()+1);
    RegCloseKey(hKey);

    return rc;
}

LSTATUS MainWindow::deleteBWRegKeys(QString path)
{
    const QString subKey = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers\\";
    LSTATUS rc = 0;
    HKEY hKey;

    rc = RegOpenKeyEx(HKEY_CURRENT_USER, (LPTSTR)subKey.utf16(), 0, KEY_WRITE, &hKey);
    if (rc)
        return rc;

    const QString bwPath = QDir::toNativeSeparators(path);
    LPTSTR lpValueName = (LPTSTR)bwPath.utf16();

    rc = RegDeleteValue(hKey, lpValueName);

    return rc;
}

void MainWindow::writeBroodWarRegs(QString path)
{
    QSettings bwRegistry(
#ifdef Q_OS_WIN64
                QLatin1String("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers"),
#else
                QLatin1String("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers"),
#endif
                QSettings::NativeFormat);

    const QString bwPath = QDir::toNativeSeparators(path);
    QString value = "~ DWM8And16BitMitigation Layer_ForceDirectDrawEmulation";

    qDebug() << path << bwPath;
    bwRegistry.setValue("h:\\broodwar\\starcraft.exe", bwPath);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //writeBWRegKeys("h:/broodwar/starcraft.exe");

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

void MainWindow::on_pbSelect_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open"), QString(), tr("Starcraft File (*.exe);;All Files (*.*)"));

    if (fileName.isEmpty())
        return;

    ui->lineEdit->setText(fileName);
}

void MainWindow::on_pbInstall_clicked()
{
    QString path = ui->lineEdit->text();
    if (path.isEmpty())
        return;

    writeBWRegKeys(path);
}

void MainWindow::on_pbUninstall_clicked()
{
    QString path = ui->lineEdit->text();
    if (path.isEmpty())
        return;
    deleteBWRegKeys(path);
}
