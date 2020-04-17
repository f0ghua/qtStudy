#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Worker;
class QThread;
class TraceModel;
class QSortFilterProxyModel;

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
    void loadFile(const QString &filePath);

private slots:
    void on_pbLoad_clicked();
    void tvDataFilter();

private:
    void startWorker();
    void stopWorker();
    void init();

    Ui::MainWindow *ui;
    Worker *m_worker = NULL;
    QThread *m_workThread = NULL;
    TraceModel *m_model;
    QSortFilterProxyModel *m_sortModel;
};

#endif // MAINWINDOW_H
