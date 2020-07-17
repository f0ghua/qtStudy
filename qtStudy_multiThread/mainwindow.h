#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    void startWorker();
    void stopWorker();

    Ui::MainWindow *ui;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
    QUdpSocket *m_socket = nullptr;
    QHostAddress m_sender;
    quint16 m_senderPort;
};

#endif // MAINWINDOW_H
