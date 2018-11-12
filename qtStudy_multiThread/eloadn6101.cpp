#include "eloadn6101.h"


#define DEVID(channel) (ELN6101_DEVID_BASE+channel)

EloadN6101::EloadN6101(QObject *parent)
    :NgiDevice(parent)
{

}

EloadN6101::EloadN6101(const QString &address, int port, QObject *parent)
    :NgiDevice(address, port, parent)
{

}

int EloadN6101::setCCMode(int channel)
{
    return devWriteUint(DEVID(channel), 10, 0);
}

int EloadN6101::setCCModeAsync(int channel)
{
    return devWriteUintAsync(DEVID(channel), 10, 0);
}

int EloadN6101::setFunctionTime(int channel, int time)
{
    return devWriteUint(DEVID(channel), 21, time);
}

int EloadN6101::setFunctionTimeAsync(int channel, int time)
{
    return devWriteUintAsync(DEVID(channel), 21, time);
}

int EloadN6101::setConfigedCurrent(int channel, double value)
{
    return devWriteFloat(DEVID(channel), 12, value);
}

int EloadN6101::setConfigedCurrentAsync(int channel, double value)
{
    return devWriteFloatAsync(DEVID(channel), 12, value);
}

int EloadN6101::setFunctionOn(int channel, bool enable)
{
    return devWriteUint(DEVID(channel), 11, enable?1:0);
}

int EloadN6101::setFunctionOnAsync(int channel, bool enable)
{
    return devWriteUintAsync(DEVID(channel), 11, enable?1:0);
}

int EloadN6101::setSaveConfig(int channel, bool enable)
{
    return devWriteUint(DEVID(channel), 22, enable?1:0);
}

quint32 EloadN6101::getCCMode(int channel)
{
    quint32 value;
    devReadUint(DEVID(channel), 10, value);
    return value;
}

quint32 EloadN6101::getFunctionTime(int channel)
{
    quint32 value;
    devReadUint(DEVID(channel), 21, value);
    return value;
}

quint32 EloadN6101::getFunctionOn(int channel)
{
    quint32 value;
    devReadUint(DEVID(channel), 11, value);
    return value;
}

double EloadN6101::getConfigedCurrent(int channel)
{
    double value = -1;
    devReadFloat(DEVID(channel), 12, value);
    return value;
}

double EloadN6101::getCurrent(int channel)
{
    double value = -1;
    devReadFloat(DEVID(channel), 3, value);
    return value;
}

int EloadN6101::getCurrentAsync(int channel)
{
    return devReadFloatAsync(DEVID(channel), 3);
}

int EloadN6101::getChannel(int devid)
{
    return (devid - ELN6101_DEVID_BASE);
}

QModbusReply *EloadN6101::setConfigedCurrentAsyncEx(int channel, double value)
{
    return devWriteFloatAsyncEx(DEVID(channel), 12, value);
}
