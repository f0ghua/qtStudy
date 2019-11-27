#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "windows.h"
#include <QMainWindow>

class Worker;
class QThread;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbSelect_clicked();

    void on_pbInstall_clicked();

    void on_pbUninstall_clicked();

private:
    void startWorker();
    void stopWorker();

    bool writeBroodWarRegKey(QString path);
    LSTATUS writeBWRegKeys(QString path);
    LSTATUS deleteBWRegKeys(QString path);
    void writeBroodWarRegs(QString path);


    Ui::MainWindow *ui;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
};

#endif // MAINWINDOW_H
