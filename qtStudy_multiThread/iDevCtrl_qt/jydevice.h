#ifndef JYDEVICE_H
#define JYDEVICE_H

#include "idevctrl_global.h"
#include <QObject>

class JYDevicePrivate;

/*!
 * \brief The JYDevice class
 *
 * The class implement base functions for products from
 * JuYing(http://www.juyingele.com.cn/)
 *
 * In the device's modbus tcp implementation, there seems a bug, the server
 * only accept one request per tcp packet. If we send with multi requests in
 * one tcp packet, no reponse from the server.
 *
 */
class IDEVCTRLIBSHARED_EXPORT JYDevice : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(JYDevice)
public:
    JYDevice(QObject *parent);
    explicit JYDevice(const QString &address, int port, QObject *parent = Q_NULLPTR);
    ~JYDevice();

	QString address() const;
	int port() const;
    int devWriteRegister(int devid, int reg, quint16 value);
    int devWriteRegisterAsync(int devid, int reg, quint16 value);
    int devWriteRegistersAsync(int devid, int reg, const QVector<quint16> &values);
    int devWriteMCHexString(int devid, const QString &hexString);
    bool connectDevice();
    bool connectToDevice(const QString &address, int port);
    bool isConnected();

protected:
    JYDevice(JYDevicePrivate &dd, QObject *parent = Q_NULLPTR);

private:
    JYDevicePrivate * const d_ptr;
    Q_DISABLE_COPY(JYDevice)
};


#endif // JYDEVICE_H
