#include "worker.h"
#include "QAppLogging.h"

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

    m_elapsedTimer.start();
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
    m_elapsedTimer.start();

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

void Worker::handleTimeout()
{
    qint64 elapsedNs = m_elapsedTimer.nsecsElapsed();
    m_elapsedTimer.start();
    double elpasedMs = static_cast<double>(elapsedNs)/1000000 + 0.5;
//    double elpasedMs = m_elapsedTimer.elapsed();
//    m_elapsedTimer.start();

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
}

void Worker::startTimer()
{
    switch (m_gv->m_clockMode) {
        case GblVar::CLOCKMODE_QTIMER:
            runQTimerProcess();
            break;
        case GblVar::CLOCKMODE_WAITABLETIMER:
            runWaitableTimerProcess();
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
        default:
            break;
    }
}

void Worker::run()
{
#if 0
    switch (m_gv->m_clockMode) {
        case GblVar::CLOCKMODE_QTIMER:
            runQTimerProcess();
            break;
        default:
            break;
    }

    while(m_isRunning) {
        //QThread::sleep(1);
        QCoreApplication::processEvents();
    }
#endif
}
