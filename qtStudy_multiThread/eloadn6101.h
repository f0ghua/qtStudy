#ifndef ELOADN6101_H
#define ELOADN6101_H

#include "ngidevice.h"

#include <QObject>

#define ELN6101_DEVID_BASE  160

class EloadN6101 : public NgiDevice
{
    Q_OBJECT
public:
    EloadN6101(QObject *parent);
    EloadN6101(const QString &address, int port, QObject *parent = Q_NULLPTR);

public slots:
    int setCCMode(int channel);
    int setFunctionTime(int channel, int time = 0);
    int setFunctionOn(int channel, bool enable = true);
    int setConfigedCurrent(int channel, double value);
    int setSaveConfig(int channel, bool enable = true);
    quint32 getCCMode(int channel);
    quint32 getFunctionTime(int channel);
    quint32 getFunctionOn(int channel);
    double getConfigedCurrent(int channel);
    double getCurrent(int channel);
    int setCCModeAsync(int channel);
    int setFunctionTimeAsync(int channel, int time = 0);
    int setConfigedCurrentAsync(int channel, double value = 0);
    int setFunctionOnAsync(int channel, bool enable);
    int getCurrentAsync(int channel);
    QModbusReply *setConfigedCurrentAsyncEx(int channel, double value);

    static int getChannel(int devid);

signals:

};

#endif // ELOADN6101_H
