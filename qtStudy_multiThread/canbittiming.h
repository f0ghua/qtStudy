#ifndef CANBITTIMING_H
#define CANBITTIMING_H

#include <QObject>

class CANBitTimingCalPrivate;

class CANBitTimingCal : public QObject
{
    Q_DECLARE_PRIVATE(CANBitTimingCal)
public:
    explicit CANBitTimingCal(QObject *parent = Q_NULLPTR);
    ~CANBitTimingCal();
    bool calcBitTimingStd(QString devName, quint32 bitrate, quint32 spt, quint32 refclk = 40000000);

protected:

private:
    CANBitTimingCalPrivate * const d_ptr;

    Q_DISABLE_COPY(CANBitTimingCal)
};

#endif // CANBITTIMING_H
