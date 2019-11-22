#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    bool startWork();

    Ui::MainWindow *ui;    
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;

    QSettings *m_settings;
    QTimer *m_timerClick;
    HWND m_hMain;
};

#endif // MAINWINDOW_H
