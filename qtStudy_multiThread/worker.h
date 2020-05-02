#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void finished();

public slots:
    void run();
    void onWorkStop();
    void onWorkStart();

private:
    bool m_isRunning;
};

#endif // WORKER_H
