#ifndef MMTIMER_H
#define MMTIMER_H

#include "windows.h"
#include "mmsystem.h"

/////////////////////////////////////////////////////////////////////////////
// CTimeCountDlg message handlers
///高精定时器结构
typedef struct tagTIMER_MEDIA{
#define TIMER_RATE 1000 //定时器时间(1000ms)
    UINT uTimerID; //定时器 ID
    UINT uResolution; //分辨率
    UINT uCont; //计数器
    HWND hWnd; //窗口句柄
}TIMER_MEDIA;

extern TIMER_MEDIA m_TimerMedia;

BOOL MilliSecondTimerStart(UINT &uTimerID, UINT uDelay, UINT &uResolution,
                              LPVOID fptc, DWORD dwUser, BOOL bSetPeriod);

void MilliSecondTimerEnd(UINT uTimerID, UINT *lpuPeriod);

#endif // MMTIMER_H
