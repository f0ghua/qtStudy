#ifndef FTUSBBACKEND_H
#define FTUSBBACKEND_H

#include "canconnection.h"
#include "ftd2xx.h"

#include <QObject>

#define ICITS_VENDOR_ID     0x0630UL

class FTUSBBackendPrivate;

class FTUSBBackend : public CANConnection
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(FTUSBBackend)
public:
    explicit FTUSBBackend(QString devName);
    virtual ~FTUSBBackend();
    FT_HANDLE getFtHandle() const;
    static QStringList getDeviceList(bool isNumberPrepend = false);

signals:

public slots:

protected:
    virtual void piStarted();
    virtual void piStop();
    virtual void piOpen();
    virtual void piClose();
    virtual bool piSendFrame(const XBusFrame &frame);

private:

    FTUSBBackendPrivate * const d_ptr;
};

#endif // FTUSBBACKEND_H
