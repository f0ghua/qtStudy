#ifndef CANBITTIMING_H
#define CANBITTIMING_H

#include <QObject>

struct CANBitTiming
{
    quint32 m_bitrate;              /* Bit-rate in bits/second */
    quint32 m_samplePoint;          /* Sample point in one-tenth of a percent */
    quint32 m_tq;                   /* Time quanta (TQ) in nanoseconds */
    quint32 m_propSeg;              /* Propagation segment in TQs */
    quint32 m_phaseSeg1;            /* Phase buffer segment 1 in TQs */
    quint32 m_phaseSeg2;            /* Phase buffer segment 2 in TQs */
    quint32 m_sjw;                  /* Synchronisation jump width in TQs */
    quint32 m_brp;                  /* Bit-rate prescaler */

    quint32 m_tseg1;                /* Time segment 1 in TQs */
    quint32 m_tseg2;                /* Time segment 2 in TQs */
    quint32 m_nbt;                  /* Nominal Bit Time in TQs */
    quint32 m_propDelay;            /* Propagation delay in nanoseconds */
    quint32 m_outputBitrate;        /* Actual Bit-rate in bits/second */
    quint32 m_outputSpt;            /* Actual Sample point in one-tenth of a percent */
};

/*!
 * \brief The FlexCANBitTiming struct
 *
 * These parameters store reg values in can controller. According to MPC5748GRM
 * CAN_CTRL1 section:
 *
 * Propagation Segment Time = (PROPSEG + 1) = m_regPropSeg + 1
 * Phase Buffer Segment 1 = (PSEG1 + 1) = m_regPhaseSeg1 + 1
 * Phase Buffer Segment 2 = (PSEG2 + 1) = m_regPhaseSeg2 + 1
 *
 */
struct FlexCANBitTiming : public CANBitTiming
{
    quint32 m_regPropSeg;           /*!< Propagation segment*/
    quint32 m_regPhaseSeg1;         /*!< Phase segment 1*/
    quint32 m_regPhaseSeg2;         /*!< Phase segment 2*/
    quint32 m_regPreDivider;        /*!< Clock prescaler division factor*/
    quint32 m_regRJumpwidth;        /*!< Resync jump width*/
};

class CANBitTimingCalPrivate;

class CANBitTimingCal : public QObject
{
    Q_DECLARE_PRIVATE(CANBitTimingCal)
public:
    explicit CANBitTimingCal(QObject *parent = Q_NULLPTR);
    ~CANBitTimingCal();
    bool calcBitTimingStd(QString devName, quint32 bitrate, quint32 spt,
                          quint32 propDelay = 910, quint32 refclk = 40000000);
    const QVector<FlexCANBitTiming> &getMatchedBitTimings();

protected:

private:
    CANBitTimingCalPrivate * const d_ptr;

    Q_DISABLE_COPY(CANBitTimingCal)
};

#endif // CANBITTIMING_H
