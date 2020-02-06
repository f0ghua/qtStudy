#include "mmtimer.h"
#include <QDebug>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

TIMER_MEDIA m_TimerMedia;

//打开定时器
//uTimerID:返回时间ID；uDelay:时钟间隔,单位(ms)；uResolution:定义分辨率,即误差
//fptc:回调函数；dwUser:用户传送到回调函数的数据;
BOOL MilliSecondTimerStart(UINT &uTimerID, UINT uDelay, UINT &uResolution,
                              LPVOID fptc, DWORD dwUser, BOOL bSetPeriod)
{
#define TIMER_ACCURACY 1 //定义时钟分辨率(1ms),即误差
    if(bSetPeriod){
        TIMECAPS tc;
        uResolution = TIMER_ACCURACY;
        //利用函数timeGetDevCaps取出系统分辨率的取值范围，如果无错则继续；
        if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) == TIMERR_NOERROR) {
            //分辨率的值不能超出系统的取值范围
            uResolution = min(max(tc.wPeriodMin, TIMER_ACCURACY), tc.wPeriodMax);
            //设置定时器的分辨率
            timeBeginPeriod(uResolution);
        }
        else {
            qDebug() << "MilliSecondTimerStart fail";
            return FALSE;
        }
    }

    qDebug() << "uResolution =" << uResolution;
    ///////////////////////////
    uTimerID = timeSetEvent(uDelay, uResolution, (LPTIMECALLBACK)fptc, dwUser, TIME_PERIODIC | TIME_CALLBACK_FUNCTION);
    if(uTimerID == 0) {
        qDebug() << "MilliSecondTimerStart timeSetEvent fail";
        return FALSE;
    }
    return TRUE;
}

//关闭定时器
void MilliSecondTimerEnd(UINT uTimerID, UINT *lpuPeriod)
{
    timeKillEvent(uTimerID); //删除定时器
    if(lpuPeriod != NULL)
        timeEndPeriod(*lpuPeriod); //删除设置的分辨率
}

static VOID CALLBACK MilliSecondProc(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
    m_TimerMedia.uCont++;
    //::SetDlgItemInt(m_TimerMedia.hWnd, IDC_EDIT1, m_TimerMedia.uCont, TRUE);
}

//MilliSecondTimerStart(m_TimerMedia.uTimerID, TIMER_RATE, m_TimerMedia.uResolution, (LPVOID)&MilliSecondProc, 0, TRUE);
//MilliSecondTimerEnd(m_TimerMedia.uTimerID, &m_TimerMedia.uResolution);
