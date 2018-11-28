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

private slots:
    void on_pbRlGetStates_clicked();

private:
    void startDevMgr();
    void stopDevMgr();
    void startWorker();
    void stopWorker();
    int rl_getAllStatesBlock(int id, QVector<double> &values);

    Ui::MainWindow *ui;
    DevManager *m_devMgr = NULL;
    QThread *m_devMgrThread = NULL;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
};

#endif // MAINWINDOW_H
