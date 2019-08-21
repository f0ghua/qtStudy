#include "canbittiming.h"

#include <QtMath>
#include <QVector>
#include <QDebug>

/*
 * CAN harware-dependent bit-timing constant
 *
 * Used for calculating and checking bit-timing parameters
 */
struct CANBitTimingConst
{
    QString m_name;                 /* Name of the CAN controller hardware */
    quint32 m_tseg1Min;             /* Time segement 1 = prop_seg + phase_seg1 */
    quint32 m_tseg1Max;
    quint32 m_tseg2Min;             /* Time segement 2 = phase_seg2 */
    quint32 m_tseg2Max;
    quint32 m_sjwMax;               /* Synchronisation jump width */
    quint32 m_brpMin;               /* Bit-rate prescaler */
    quint32 m_brpMax;
    quint32 m_brpInc;
    quint32 m_ipt;
    quint32 m_nbtMin;
    quint32 m_nbtMax;
    quint32 m_propsegMax;           /* REG max value +1 */
    quint32 m_pseg1Max;             /* REG max value +1 */
    quint32 m_pseg2Max;             /* REG max value +1 */

    quint32 m_refClk;               /* CAN system clock frequency in Hz */
    void (*m_fnPrintfBtr)(CANBitTiming *cbt, int hdr);
    void (*m_fnSetFlexCANBitTiming)(CANBitTiming *cbt, FlexCANBitTiming *fbt);
};

/*
 * CAN clock parameters
 */
struct CANClock
{
    quint32 m_freq; /* CAN system clock frequency in Hz */
};

/*
 * minimal structs, just enough to be source level compatible
 */
struct CANPriv
{
    const CANBitTimingConst *m_bittimingConst;
    CANClock m_clock;
};

struct CANNetDevice
{
    CANPriv m_priv;
};

static void setFlexCANBitTimingStd(CANBitTiming *cbt, FlexCANBitTiming *fbt);
static void setFlexCANBitTimingFdData(CANBitTiming *cbt, FlexCANBitTiming *fbt);

static CANBitTimingConst g_canCalcConsts[] = {

    {
        .m_name = "flexcan_std",
        .m_tseg1Min = 2, .m_tseg1Max = 16, .m_tseg2Min = 2, .m_tseg2Max = 8,
        .m_sjwMax = 4, .m_brpMin = 1, .m_brpMax = 1024, .m_brpInc = 1,
        .m_ipt = 2, .m_nbtMin = 8, .m_nbtMax = 129, .m_propsegMax = 8,
        .m_pseg1Max = 8, .m_pseg2Max = 8,
        .m_refClk = 40000000,
        .m_fnPrintfBtr = nullptr,
        .m_fnSetFlexCANBitTiming = setFlexCANBitTimingStd,
    },

    { // flexcan fd arbiration
        .m_name = "flexcan_fda",
        .m_tseg1Min = 2, .m_tseg1Max = 96, .m_tseg2Min = 2, .m_tseg2Max = 32,
        .m_sjwMax = 4, .m_brpMin = 1, .m_brpMax = 1024, .m_brpInc = 1,
        .m_ipt = 2, .m_nbtMin = 8, .m_nbtMax = 129, .m_propsegMax = 64,
        .m_pseg1Max = 32, .m_pseg2Max = 32,
        .m_refClk = 40000000,
        .m_fnPrintfBtr = nullptr,
        .m_fnSetFlexCANBitTiming = setFlexCANBitTimingStd,
    },

    { // flexcan fd data
        .m_name = "flexcan_fdd",
        .m_tseg1Min = 2, .m_tseg1Max = 39, .m_tseg2Min = 2, .m_tseg2Max = 8,
        .m_sjwMax = 4, .m_brpMin = 1, .m_brpMax = 1024, .m_brpInc = 1,
        .m_ipt = 2, .m_nbtMin = 5, .m_nbtMax = 48, .m_propsegMax = 32,
        .m_pseg1Max = 8, .m_pseg2Max = 8,
        .m_refClk = 40000000,
        .m_fnPrintfBtr = nullptr,
        .m_fnSetFlexCANBitTiming = setFlexCANBitTimingFdData,
    },
};

static void copyCANBitTiming(CANBitTiming *cbt, FlexCANBitTiming *fbt)
{
    fbt->m_bitrate = cbt->m_bitrate;
    fbt->m_samplePoint = cbt->m_samplePoint;
    fbt->m_tq = cbt->m_tq;
    fbt->m_propSeg = cbt->m_propSeg;
    fbt->m_phaseSeg1 = cbt->m_phaseSeg1;
    fbt->m_phaseSeg2 = cbt->m_phaseSeg2;
    fbt->m_sjw = cbt->m_sjw;
    fbt->m_brp = cbt->m_brp;
    fbt->m_tseg1 = cbt->m_tseg1;
    fbt->m_tseg2 = cbt->m_tseg2;
    fbt->m_nbt = cbt->m_nbt;
    fbt->m_propDelay = cbt->m_propDelay;
    fbt->m_outputBitrate = cbt->m_outputBitrate;
    fbt->m_outputSpt = cbt->m_outputSpt;
}

static void setFlexCANBitTimingStd(CANBitTiming *cbt, FlexCANBitTiming *fbt)
{
    copyCANBitTiming(cbt, fbt);

    fbt->m_regPropSeg = cbt->m_propSeg - 1;
    fbt->m_regPhaseSeg1 = cbt->m_phaseSeg1 - 1;
    fbt->m_regPhaseSeg2 = cbt->m_phaseSeg2 - 1;
    fbt->m_regRJumpwidth = cbt->m_sjw - 1;
    fbt->m_regPreDivider = cbt->m_brp - 1;

    return;
}

static void setFlexCANBitTimingFdData(CANBitTiming *cbt, FlexCANBitTiming *fbt)
{
    copyCANBitTiming(cbt, fbt);

    fbt->m_regPropSeg = cbt->m_propSeg;
    fbt->m_regPhaseSeg1 = cbt->m_phaseSeg1 - 1;
    fbt->m_regPhaseSeg2 = cbt->m_phaseSeg2 - 1;
    fbt->m_regRJumpwidth = cbt->m_sjw - 1;
    fbt->m_regPreDivider = cbt->m_brp - 1;

    return;
}

static int canUpdateSpt( const struct CANBitTimingConst *btc,
                         int spt, int tseg, int *tseg1, int *tseg2 )
{
    *tseg2 = tseg + 1 - ( spt * ( tseg + 1 ) ) / 1000;
    if ( *tseg2 < static_cast<int>(btc->m_tseg2Min) )
        *tseg2 = btc->m_tseg2Min;
    if ( *tseg2 > static_cast<int>(btc->m_tseg2Max) )
        *tseg2 = btc->m_tseg2Max;
    *tseg1 = tseg - *tseg2;
    if ( *tseg1 > static_cast<int>(btc->m_tseg1Max) ) {
        *tseg1 = btc->m_tseg1Max;
        *tseg2 = tseg - *tseg1;
    }

    return 1000 * ( tseg + 1 - *tseg2 ) / ( tseg + 1 );
}

static bool updateCANBitTiming(
        CANBitTiming *bt,
        quint32 tq, quint32 propseg, quint32 pseg1, quint32 pseg2, quint32 brp, quint32 clk)
{
    bt->m_tq = tq;
    bt->m_propSeg = propseg;
    bt->m_phaseSeg1 = pseg1;
    bt->m_phaseSeg2 = pseg2;
    bt->m_sjw = 2;
    bt->m_brp = brp;
    bt->m_tseg1 = propseg + pseg1;
    bt->m_tseg2 = pseg2;
    bt->m_nbt = 1 + propseg + pseg1 + pseg2;
    bt->m_outputSpt = 1000 * ( bt->m_tseg1  + 1) / bt->m_nbt;
    bt->m_outputBitrate = clk / ( brp * bt->m_nbt );

    return ((bt->m_bitrate == bt->m_outputBitrate) && (bt->m_samplePoint == bt->m_outputSpt));
}

class CANBitTimingCalPrivate
{
    Q_DECLARE_PUBLIC(CANBitTimingCal)
public:
    CANBitTimingCalPrivate(CANBitTimingCal *parent);
    virtual ~CANBitTimingCalPrivate();

    bool calcBitTimingStd(QString devName, quint32 bitrate, quint32 spt, quint32 refclk);
    bool calcBitTimingCommonStd(CANNetDevice *dev, CANBitTiming *bt);
    bool calcBitTimingStd(CANNetDevice *dev, CANBitTiming *bt);
    bool calcBitTimingFD(CANNetDevice *dev, CANBitTiming *bt);

    CANBitTimingCal * const q_ptr;
    QVector<FlexCANBitTiming> m_matchedBitTimings;
};

CANBitTimingCalPrivate::CANBitTimingCalPrivate(CANBitTimingCal *parent)
    : q_ptr(parent)
{
    Q_Q(CANBitTimingCal);

}

CANBitTimingCalPrivate::~CANBitTimingCalPrivate()
{

}

bool CANBitTimingCalPrivate::calcBitTimingCommonStd(CANNetDevice *dev, CANBitTiming *bt)
{
    CANPriv *priv = &dev->m_priv;
    const struct CANBitTimingConst *btc = priv->m_bittimingConst;
    long rate = 0;
    long bestError = 1000000000, error = 0;
    int bestTseg = 0, bestBrp = 0, brp = 0;
    int nbt, tseg = 0, tseg1 = 0, tseg2 = 0;
    int sptError = 1000, spt = 0, samplePoint;
    quint64 v64;

    if ( !priv->m_bittimingConst )
        return false;

    m_matchedBitTimings.clear();

    /* Use CIA recommended sample points */
    if ( bt->m_samplePoint ) {
        samplePoint = bt->m_samplePoint;
    } else {
        if ( bt->m_bitrate > 800000 )
            samplePoint = 750;
        else if ( bt->m_bitrate > 500000 )
            samplePoint = 800;
        else
            samplePoint = 875;
    }

    /* tseg even = round down, odd = round up */
    for ( tseg = ( btc->m_tseg1Max + btc->m_tseg2Max ) * 2 + 1;
          static_cast<quint32>(tseg) >= ( btc->m_tseg1Min + btc->m_tseg2Min ) * 2;
          tseg-- ) {
        nbt = 1 + tseg / 2;
        /* Compute all possible tseg choices (tseg = tseg1+tseg2) */
        brp = priv->m_clock.m_freq / ( nbt * bt->m_bitrate ) + tseg % 2;
        /* chose brp step which is possible in system */
        brp = ( brp / btc->m_brpInc ) * btc->m_brpInc;
        if ( ( brp < static_cast<int>(btc->m_brpMin) ) ||
             ( brp > static_cast<int>(btc->m_brpMax) ) )
            continue;

        rate = priv->m_clock.m_freq / ( brp * nbt );
        error = bt->m_bitrate - rate;
        /* record the one best match the disired bitrate */
        if ( error < 0 )
            error = -error;
        if ( error > bestError )
            continue;
        bestError = error;

        /* bitrate is exactly match, update simple point and do match checking */
        if ( error == 0 ) {
            spt = canUpdateSpt( btc, samplePoint, tseg / 2, &tseg1, &tseg2 );
            error = samplePoint - spt;
            if ( error < 0 )
                error = -error;
            if ( error > sptError )
                continue;
            sptError = error;
        }
        bestTseg = tseg / 2;
        bestBrp = brp;

        /* simple point match too, let's record the right parameters */
        if ( error == 0 ) {
            /* real sample point */
            bt->m_samplePoint = spt;
            v64 = (quint64) bestBrp * 1000000000UL;
            v64 = v64 / priv->m_clock.m_freq;
            bt->m_tq = (quint32) v64;
            bt->m_propSeg = (tseg1/2);
            quint32 reminder = nbt - 1 - bt->m_propSeg;
            if (reminder % 2) {
                bt->m_propSeg++;
            }
            bt->m_phaseSeg1 = tseg1 - bt->m_propSeg;
            bt->m_phaseSeg2 = tseg2;
            bt->m_sjw = 2;
            bt->m_brp = bestBrp;
            bt->m_bitrate = priv->m_clock.m_freq / ( bt->m_brp * ( tseg1 + tseg2 + 1 ) );

            bt->m_tseg1 = tseg1;
            bt->m_tseg2 = tseg2;
            bt->m_nbt = nbt;

            FlexCANBitTiming fbt;
            if (btc->m_fnSetFlexCANBitTiming) {
                btc->m_fnSetFlexCANBitTiming(bt, &fbt);
            }
            m_matchedBitTimings.append(fbt);
        }
    }

    return m_matchedBitTimings.isEmpty()?false:true;
}

bool CANBitTimingCalPrivate::calcBitTimingStd(CANNetDevice *dev, CANBitTiming *bt)
{
    CANPriv *priv = &dev->m_priv;
    const struct CANBitTimingConst *btc = priv->m_bittimingConst;
    int brp = 0;
    int nbt = 0, tseg1 = 0, tseg2 = 0;
    int tq = 0, propseg = 0, pseg1 = 0, pseg2 = 0, pseg = 0; // mapping to standard, not NXP's REG

    if ( !priv->m_bittimingConst )
        return false;

    m_matchedBitTimings.clear();

    for (brp = btc->m_brpMin; brp <= btc->m_brpMax; brp++) {
        quint32 radio = priv->m_clock.m_freq / bt->m_bitrate;
        nbt = radio / brp;
        if ((priv->m_clock.m_freq % bt->m_bitrate)||(radio % brp)) {
            continue;
        }
        if ((nbt < btc->m_nbtMin) || (nbt > btc->m_nbtMax)) {
            continue;
        }

        tq = 1000000000UL * static_cast<quint64>(brp) / priv->m_clock.m_freq;
        propseg = qCeil(static_cast<double>(bt->m_propDelay) / tq);
        if (propseg > btc->m_propsegMax) {
            continue;
        }

        //tseg1 = qRound(nbt * static_cast<double>(bt->m_samplePoint)/1000) - 1/* SYNC_SEG */;
        tseg1 = qFloor((nbt * static_cast<double>(bt->m_samplePoint)/1000) + 0.5) - 1 /* SYNC_SEG */;
        tseg2 = nbt - 1 - tseg1;
        pseg1 = tseg1 - propseg;
        pseg2 = tseg2;

        if ((pseg2 >= btc->m_ipt) && (pseg2 <= btc->m_pseg2Max) &&
                (pseg1 >= 0) && (pseg1 <= btc->m_pseg1Max)) {
            // found a right one, record it and continue
            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }

        pseg = nbt - 1 - propseg;
        if ((pseg == 3) && (btc->m_ipt == 2)) {
            // found a right one, record it and continue
            pseg1 = 1;
            pseg2 = 2;

            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }

        if ((pseg > (btc->m_ipt + 1)) && (pseg  <= (pseg1*2))) {
            if (pseg % 2) {
                propseg = propseg + 1;
            }
            pseg1 = (nbt - 1 - propseg)/2;
            pseg2 = nbt - 1 - propseg - pseg1;

            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }
    }

    return m_matchedBitTimings.isEmpty()?false:true;
}

bool CANBitTimingCalPrivate::calcBitTimingFD(CANNetDevice *dev, CANBitTiming *bt)
{
    CANPriv *priv = &dev->m_priv;
    const struct CANBitTimingConst *btc = priv->m_bittimingConst;
    int brp = 0;
    int nbt = 0, tseg1 = 0, tseg2 = 0;
    int tq = 0, propseg = 0, pseg1 = 0, pseg2 = 0, pseg = 0; // mapping to standard, not NXP's REG
    int tdcen = 0;

    if ( !priv->m_bittimingConst )
        return false;

    m_matchedBitTimings.clear();

    for (brp = btc->m_brpMin; brp <= btc->m_brpMax; brp++) {
        quint32 radio = priv->m_clock.m_freq / bt->m_bitrate;
        nbt = radio / brp;
        if ((priv->m_clock.m_freq % bt->m_bitrate)||(radio % brp)) {
            continue;
        }
        if ((nbt < btc->m_nbtMin) || (nbt > btc->m_nbtMax)) {
            continue;
        }

        tq = 1000000000UL * static_cast<quint64>(brp) / priv->m_clock.m_freq;
        propseg = qCeil(static_cast<double>(bt->m_propDelay) / tq);
        if (propseg > btc->m_propsegMax) {
            continue;
        }

        if (propseg > (nbt - 2)) {
            int propsegMax = nbt - 3;
            int propsegMin = nbt - 1 - btc->m_pseg1Max - btc->m_pseg2Max;
            if (propsegMin < 1) {
                propsegMin = 1;
            }
            propseg = qFloor((static_cast<double>(propsegMax - propsegMin)/2) + 0.5);
            tdcen = 1;
        }

        if (propseg > btc->m_propsegMax) {
            continue;
        }

        //tseg1 = qRound(nbt * static_cast<double>(bt->m_samplePoint)/1000) - 1/* SYNC_SEG */;
        tseg1 = qFloor((nbt * static_cast<double>(bt->m_samplePoint)/1000) + 0.5) - 1 /* SYNC_SEG */;
        tseg2 = nbt - 1 - tseg1;
        pseg1 = tseg1 - propseg;
        pseg2 = tseg2;

        if ((pseg2 >= btc->m_ipt) && (pseg2 <= btc->m_pseg2Max) &&
                (pseg1 >= 0) && (pseg1 <= btc->m_pseg1Max)) {
            // found a right one, record it and continue
            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }

        pseg = nbt - 1 - propseg;
        if ((pseg == 3) && (btc->m_ipt == 2)) {
            // found a right one, record it and continue
            pseg1 = 1;
            pseg2 = 2;

            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }

        if ((pseg > (btc->m_ipt + 1)) && (pseg  <= (pseg1*2))) {
            if (pseg % 2) {
                propseg = propseg + 1;
            }
            pseg1 = (nbt - 1 - propseg)/2;
            pseg2 = nbt - 1 - propseg - pseg1;

            bool ret = updateCANBitTiming(bt, tq, propseg, pseg1, pseg2, brp, priv->m_clock.m_freq);
            if (ret) {
                FlexCANBitTiming fbt;
                if (btc->m_fnSetFlexCANBitTiming) {
                    btc->m_fnSetFlexCANBitTiming(bt, &fbt);
                }
                m_matchedBitTimings.append(fbt);
            }
            continue;
        }
    }

    return m_matchedBitTimings.isEmpty()?false:true;
}

CANBitTimingCal::CANBitTimingCal(QObject *parent)
    : QObject(parent)
    , d_ptr(new CANBitTimingCalPrivate(this))
{
    Q_D(CANBitTimingCal);
}

CANBitTimingCal::~CANBitTimingCal()
{
    delete d_ptr;
}

/*!
 * \brief CANBitTimingCal::calcBitTimingStd
 * \param devName
 * \param bitrate
 * \param spt
 * \param refclk
 * \param propDelay tPROP_SEG = 2(tBUS + tTX + tRX), default tTX=tRX=255, tBUS=20M*5ns
 * \return
 */
bool CANBitTimingCal::calcBitTimingStd(QString devName, quint32 bitrate, quint32 spt,
                                       quint32 propDelay, quint32 refclk)
{
    struct CANNetDevice dev;
    CANBitTiming bt;
    bool isFound = false;
    quint8 i;

    Q_D(CANBitTimingCal);

    for (i = 0; i < sizeof(g_canCalcConsts)/sizeof(CANBitTimingConst); i++) {
        if ( devName == g_canCalcConsts[i].m_name ) {
            isFound = true;
            break;
        }
    }

    if (!isFound)
        return false;

    dev.m_priv.m_bittimingConst = &g_canCalcConsts[i];
    dev.m_priv.m_clock.m_freq = refclk;
    bt.m_bitrate = bitrate;
    bt.m_samplePoint = spt;
    bt.m_propDelay = propDelay;

    bool ret = d->calcBitTimingFD(&dev, &bt);
    if (!ret) {
        return false;
    }

    for (const FlexCANBitTiming &fbt : d->m_matchedBitTimings) {
        qDebug() << QObject::tr("TQ(%1) NBT(%2) TS1(%3) TS2(%4) PRS(%5) PS1(%6) PS2(%7) BRP(%8) RJW(%9) SPT(%10)").\
                    arg(fbt.m_tq).\
                    arg(fbt.m_nbt).\
                    arg(fbt.m_tseg1).\
                    arg(fbt.m_tseg2).\
                    arg(fbt.m_regPropSeg).\
                    arg(fbt.m_regPhaseSeg1).\
                    arg(fbt.m_regPhaseSeg2).\
                    arg(fbt.m_regPreDivider).\
                    arg(fbt.m_regRJumpwidth).\
                    arg(fbt.m_outputSpt);
    }

    return true;
}

const QVector<FlexCANBitTiming> &CANBitTimingCal::getMatchedBitTimings()
{
    Q_D(CANBitTimingCal);
    return d->m_matchedBitTimings;
}
