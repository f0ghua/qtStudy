#ifndef WORKER_H
#define WORKER_H

#include "xtypes.h"

#include <QObject>
#include <QElapsedTimer>

class QTimer;

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(GblVar *gv, QObject *parent = nullptr);

signals:

public slots:
    void run();
    void handleTimeout();
    void startTimer();
    void stopTimer();

private:
    void runQTimerProcess();
    void endQTimerProcess();

    bool m_isRunning = true;
    GblVar *m_gv;
    QElapsedTimer m_elapsedTimer;
    int m_runCount = 0;
    double m_totalTime = 0.0;
    QTimer *m_timer;
};

#endif // WORKER_H
