#ifndef IENGINEBACKEND_H
#define IENGINEBACKEND_H

#include "canconnection.h"

class IEngineBackendPrivate;

class IEngineBackend : public CANConnection
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(IEngineBackend)
public:
    explicit IEngineBackend(QString devName);
    virtual ~IEngineBackend();

    bool isConnected();

signals:
    void devConnected();
    void devDisconnected();

public slots:
    void run();
    QStringList availablePorts();
    void setServerAddress(const QString &ip, int port);
    bool connectDevice(const QString &devName);
    bool disconnectDevice();
    void halWrite(const QByteArray &data);

protected:
    virtual void piStarted();
    virtual void piStop();
    virtual void piOpen();
    virtual void piClose();
    virtual bool piSendFrame(const XBusFrame &frame);

private:
    IEngineBackendPrivate * d_ptr = NULL;
};

#endif // IENGINEBACKEND_H
