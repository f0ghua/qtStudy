#include "worker.h"
#include "QAppLogging.h"

//#define USE_NtSetTimerResolution
#ifdef USE_NtSetTimerResolution
#include "dynamicLibrary.h"
DYNAMIC_IMPORT("ntdll.dll", NtSetTimerResolution, NTSTATUS(ULONG DesiredResolution, BOOLEAN SetResolution, PULONG CurrentResolution));
#endif

#include <qmath.h>
#include <QTimer>
#include <QEventLoop>
#include <QThread>
#include <QCoreApplication>

Worker::Worker(GblVar *gv, QObject *parent)
    : QObject(parent)
    , m_gv(gv)
{

}

void Worker::runQTimerProcess()
{
    m_timer = new QTimer(this);
    m_timer->setInterval(m_gv->m_clockRate);
    //timer->setTimerType(Qt::PreciseTimer);
    connect(m_timer, &QTimer::timeout, this, &Worker::handleTimeout);

    m_timer->start();

    QEventLoop eventLoop;
    eventLoop.exec();
}

void Worker::endQTimerProcess()
{
    m_timer->stop();
}

void Worker::runWaitableTimerProcess()
{
    m_isRunning = true;

    // setup waitable Win32 periodic timer
    m_hTimerEvent = (HANDLE)CreateWaitableTimer(NULL, false, NULL);
    if (!m_hTimerEvent) {
        qDebug() << "CreateWaitableTimer return false";
        return;
    }

    LARGE_INTEGER tLT;
    tLT.QuadPart = 0;
    if (!SetWaitableTimer(m_hTimerEvent, &tLT, m_gv->m_clockRate, NULL, NULL, true)) {
        CloseHandle(m_hTimerEvent);
        m_hTimerEvent = NULL;
    }
    qDebug() << "m_gv->m_clockRate" << m_gv->m_clockRate;

    // wait for 10 ticks for stable timing
    WaitForSingleObject(m_hTimerEvent, m_gv->m_clockRate*10);

    // start our timing loop, wait for abort flag
    while (m_isRunning) {

        HANDLE ah[1] = { m_hTimerEvent };
        DWORD dwRet = ::MsgWaitForMultipleObjects(1, ah, FALSE, INFINITE, QS_ALLINPUT);
        switch (dwRet - WAIT_OBJECT_0) {
            case 0: {
                handleTimeout();
                break;
            }
            default:
                QCoreApplication::processEvents();
                break;
        }
    }
}

void Worker::endWaitableTimerProcess()
{
    m_isRunning = false;
    if (m_hTimerEvent != NULL) {
        CloseHandle(m_hTimerEvent);
        m_hTimerEvent = NULL;
    }
}

static VOID CALLBACK mmTimerCallback(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    Q_UNUSED(uTimerID);
    Q_UNUSED(uMsg);
    Q_UNUSED(dw1);
    Q_UNUSED(dw2);

    Worker *worker = (Worker *)dwUser;
    worker->handleTimeout();
}

void Worker::runMmTimerProcess()
{
    m_isRunning = true;
    m_mmTimerId = timeSetEvent(m_gv->m_clockRate, 0,
                               (LPTIMECALLBACK)mmTimerCallback,
                               (DWORD_PTR)this,
                               TIME_PERIODIC|TIME_CALLBACK_FUNCTION);
    qDebug() << "m_mmTimerId =" << m_mmTimerId;
}

void Worker::endMmTimerProcess()
{
    if (m_mmTimerId != 0) {
        timeKillEvent(m_mmTimerId);
        m_mmTimerId = 0;
    }
}

typedef std::chrono::microseconds microseconds;

void Worker::runBlockTimerProcess()
{
    m_countingTimer = new Timer();
    m_countingTimer->start();

    while(m_isRunning) {
        static quint64 t2 = 0;

#if 0
        Sleep(1);
        //QCoreApplication::processEvents();

        quint64 t1 = timeGetTime();
        quint64 v4 = t1 - t2;
        //qDebug() << "v4 =" << v4 << ", t1 =" << t1 << ", t2 =" << t2;

        if (v4) {
            int v6 = 0;
            t2 = t1;
            do {
                v6++;

                if (m_countingTimer->nsecsElapsed() >= (1000000 * m_gv->m_clockRate)) {
                    handleTimeout();
                    m_countingTimer->start();
                } else {
                    std::this_thread::sleep_for(microseconds(25));
                    //QCoreApplication::processEvents();
                }
            } while ((timeGetTime() < (t1+25)) && (v4 > v6));
        }
#else
        if (m_countingTimer->nsecsElapsed() >= (1000000 * m_gv->m_clockRate)) {
            handleTimeout();
            m_countingTimer->start();
        } else {
            std::this_thread::sleep_for(microseconds(1));
            //QCoreApplication::processEvents();
        }
#endif
    }
}

void Worker::endBlockTimerProcess()
{
    m_isRunning = false;
    delete m_countingTimer;
}

void Worker::handleTimeout()
{
    if (!m_isElapsedTimerExecuted) {
        m_isElapsedTimerExecuted = true;
        m_elapsedTimer.start();
        return;
    }

    //double elpasedMs = m_elapsedTimer.elapsed();
    qint64 elapsedNs = m_elapsedTimer.nsecsElapsed();
    double elpasedMs = static_cast<double>(elapsedNs)/1000000;
    if (m_gv->m_clockMode != GblVar::CLOCKMODE_BLOCKTIMER) {
        elpasedMs += 0.5;
    }
    qDebug() << "elpasedMs =" << elpasedMs;

    int h = static_cast<int>(elpasedMs);
    if (h < 0) h = 0;
    if (h >= HMAX) {
        h = HMAX - 1;
    }
    if (++m_gv->m_totalCount > 10) m_gv->m_hSec[h]++;

    m_totalTime += elpasedMs;
    m_runCount++;
    if (m_runCount >= 100) {
        m_gv->m_actualRate = m_totalTime/m_runCount;
        m_totalTime = 0;
        m_runCount = 0;
    }

    m_elapsedTimer.start();
}

void Worker::setSystemResolution()
{
#ifdef USE_NtSetTimerResolution
    {
#define STATUS_SUCCESS 0
#define STATUS_TIMER_RESOLUTION_NOT_SET 0xC0000245
        // after loading NtSetTimerResolution from ntdll.dll:
        m_requestedResolution = 5000;
        m_currentResolution = 0;

        // 1. Requesting a higher resolution
        if (NtSetTimerResolution(m_requestedResolution, TRUE, &m_currentResolution) != STATUS_SUCCESS) {
            // The call has failed
            qDebug() << "NtSetTimerResolution call failed";
        }

        qDebug() << "m_currentResolution [100 ns units]:" << m_currentResolution;
        // this will show 5000 on more modern platforms (0.5ms!)
        // do your stuff here at 0.5 ms timer resolution
    }
#else
    {
        // Set resolution to the minimum supported by the system.
        TIMECAPS tc;
        timeGetDevCaps(&tc, sizeof(TIMECAPS));
        m_mmTimerResolution = qMin(qMax(tc.wPeriodMin, (UINT) 0), tc.wPeriodMax);
        timeBeginPeriod(m_mmTimerResolution);
    }
#endif
}

void Worker::clearSystemResolution()
{
#ifdef USE_NtSetTimerResolution
    {
        // 2. Releasing the requested resolution
        switch (NtSetTimerResolution(m_requestedResolution, FALSE, &m_currentResolution)) {
            case STATUS_SUCCESS:
                qDebug() << "The current resolution has returned to [100 ns units]" << m_currentResolution;
                break;
            case STATUS_TIMER_RESOLUTION_NOT_SET:
                qDebug() << "The requested resolution was not set\n";
                // the resolution can only return to a previous value by means of FALSE
                // when the current resolution was set by this application
                break;
            default:
                // The call has failed
                break;
        }
    }
#else
    timeBeginPeriod(m_mmTimerResolution);
#endif
}

void Worker::startTimer()
{

    m_isElapsedTimerExecuted = false;

    setSystemResolution();

    SetThreadAffinityMask(GetCurrentThread(), m_gv->m_cpuMask);
    DWORD n = GetCurrentProcessorNumber();
    qDebug() << "GetCurrentProcessorNumber return" << n;

    switch (m_gv->m_clockMode) {
        case GblVar::CLOCKMODE_QTIMER:
            runQTimerProcess();
            break;
        case GblVar::CLOCKMODE_WAITABLETIMER:
            runWaitableTimerProcess();
            break;
        case GblVar::CLOCKMODE_MMTIMER:
            runMmTimerProcess();
            break;
        case GblVar::CLOCKMODE_BLOCKTIMER:
            runBlockTimerProcess();
            break;
        default:
            break;
    }
}

void Worker::stopTimer()
{
    switch (m_gv->m_clockMode) {
        case GblVar::CLOCKMODE_QTIMER:
            endQTimerProcess();
            break;
        case GblVar::CLOCKMODE_WAITABLETIMER:
            endWaitableTimerProcess();
            break;
        case GblVar::CLOCKMODE_MMTIMER:
            endMmTimerProcess();
            break;
        case GblVar::CLOCKMODE_BLOCKTIMER:
            endBlockTimerProcess();
            break;
        default:
            break;
    }

    clearSystemResolution();
}

void Worker::run()
{

}
