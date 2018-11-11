#ifndef NGIDEVICE_H
#define NGIDEVICE_H

#include "idevctrl_global.h"
#include <QObject>

class NgiDevicePrivate;

class IDEVCTRLIBSHARED_EXPORT NgiDevice : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(NgiDevice)
public:
    NgiDevice(QObject *parent);
    explicit NgiDevice(const QString &address, int port, QObject *parent = Q_NULLPTR);
    ~NgiDevice();

    const QString &address() const;
    int port() const;
    int devReadUint(int devid, int reg, uint &value);
    int devReadFloat(int devid, int reg, double &value);
    int devWriteUint(int devid, int reg, uint value);
    int devWriteFloat(int devid, int reg, double value);
    int devReadFloatAsync(int devid, int reg);
    int devWriteUintAsync(int devid, int reg, uint value);
    int devWriteFloatAsync(int devid, int reg, double value);
    bool connectDevice();
    bool connectToDevice(const QString &address, int port);
    bool isConnected();
    int devWriteRawDataAsync(const QByteArray &ba);

signals:
    void responseValueGet(const QString &address, int devid, int reg, double value);

protected:
    NgiDevice(NgiDevicePrivate &dd, QObject *parent = Q_NULLPTR);

private:
    NgiDevicePrivate * const d_ptr;
    Q_DISABLE_COPY(NgiDevice)
};


#endif // NGIDEVICE_H
