#ifndef XTYPES_H
#define XTYPES_H

#include <qglobal.h>

struct GblVar {
#define HMAX 300

    enum {
        CLOCKMODE_QTIMER = 0,
        CLOCKMODE_WAITABLETIMER,
        CLOCKMODE_MMTIMER,
        CLOCKMODE_BLOCKTIMER,
    };

    quint64 m_hSec[HMAX];
    quint32 m_clockRate     = 10;
    quint8 m_clockMode      = CLOCKMODE_QTIMER;
    double m_totalTime      = 0.0;
    quint32 m_totalCount    = 0;
    double m_actualRate     = 0.0;
    quint32 m_cpuMask       = 0x000F;
};

#endif // XTYPES_H
