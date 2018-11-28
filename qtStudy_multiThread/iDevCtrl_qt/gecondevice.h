#ifndef GECONDEVICE_H
#define GECONDEVICE_H

#include "idevctrl_global.h"
#include <QObject>

class GeconDevicePrivate;

class IDEVCTRLIBSHARED_EXPORT GeconDevice : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(GeconDevice)
public:
    GeconDevice(QObject *parent);
    explicit GeconDevice(const QString &comPort, QObject *parent = Q_NULLPTR, int baudate = 9600);
    ~GeconDevice();

    const QString &comPort() const;
    int baudrate() const;
    bool connectDevice();
    bool connectToDevice(const QString &address, int port);
    bool isConnected();
    int devReadRegistersAsync(int devid, int reg, int number);

signals:
    void responseValueGet(const QString &address, int devid, int reg, double value);

protected:
    GeconDevice(GeconDevicePrivate &dd, QObject *parent = Q_NULLPTR);

private:
    GeconDevicePrivate * const d_ptr;
    Q_DISABLE_COPY(GeconDevice)
};


#endif // NGIDEVICE_H
