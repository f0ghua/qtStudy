#ifndef WORKER_H
#define WORKER_H

#include "xtypes.h"
#include "windows.h"
#include "timer.h"

#include <QObject>
#include <QElapsedTimer>

//typedef QElapsedTimer Timer;
typedef ChronoElapsedTimer Timer;

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
    void setSystemResolution();
    void clearSystemResolution();
    void runQTimerProcess();
    void endQTimerProcess();
    void runWaitableTimerProcess();
    void endWaitableTimerProcess();
    void runMmTimerProcess();
    void endMmTimerProcess();

    bool m_isRunning = true;
    GblVar *m_gv;
    int m_runCount = 0;
    double m_totalTime = 0.0;
    QTimer *m_timer;
    HANDLE m_hTimerEvent = NULL;
#define INVALID_MMTIMER_ID ((UINT)-1)
    UINT m_mmTimerId = INVALID_MMTIMER_ID;
    UINT m_mmTimerResolution = 0;
    ULONG m_requestedResolution = 5000;
    ULONG m_currentResolution = 0;
    Timer m_elapsedTimer;
    bool m_isElapsedTimerExecuted = false;
};

#endif // WORKER_H
