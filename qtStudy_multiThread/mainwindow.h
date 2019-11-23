#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>

class Worker;
class QThread;
class QSettings;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void handleClickTimeout();

private:
#ifdef THREAD_ENABLE
    void startWorker();
    void stopWorker();
#endif
    bool prepareWork();
    void startWork();
    bool closeWindows();

    Ui::MainWindow *ui;    
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;

    QSettings *m_settings;
    QTimer *m_timerClick;
    POINT m_point;
};

#endif // MAINWINDOW_H
