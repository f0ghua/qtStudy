#ifndef WORKER_H
#define WORKER_H

#include "xtypes.h"
#include "windows.h"

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
    void runWaitableTimerProcess();
    void endWaitableTimerProcess();
    void runMmTimerProcess();
    void endMmTimerProcess();

    bool m_isRunning = true;
    GblVar *m_gv;
    QElapsedTimer m_elapsedTimer;
    int m_runCount = 0;
    double m_totalTime = 0.0;
    QTimer *m_timer;
    HANDLE m_hTimerEvent = NULL;
    UINT m_mmTimerId = -1;
    UINT m_mmTimerResolution = 0;
    ULONG m_requestedResolution = 5000;
    ULONG m_currentResolution = 0;
};

#endif // WORKER_H
