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

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void startWorker();
    void stopWorker();
    bool extractAttachedFile(const QString &filePath);

    Ui::MainWindow *ui;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
};

#endif // MAINWINDOW_H
