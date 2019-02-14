#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

signals:
    void workStop();

private slots:
    void onMsgDump(const QString &msg);
    void on_pbConnect_clicked();
    void on_pbStart_clicked();
    void on_pbStop_clicked();

private:
    void startWorker();
    void stopWorker();
    void initWidgets();

    Ui::MainWindow *ui;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
};

#endif // MAINWINDOW_H
