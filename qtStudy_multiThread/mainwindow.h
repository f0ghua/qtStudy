#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DevManager;
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

private:
    void startDevMgr();
    void stopDevMgr();
    void startWorker();
    void stopWorker();

    Ui::MainWindow *ui;
    DevManager *m_devMgr = NULL;
    QThread *m_devMgrThread = NULL;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
};

#endif // MAINWINDOW_H
