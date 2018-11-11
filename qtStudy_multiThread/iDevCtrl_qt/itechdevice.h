#ifndef ITECHDEVICE_H
#define ITECHDEVICE_H

#include "idevctrl_global.h"

#include <QObject>
#include <QTimer>
#include <QPointer>

class ITechDevicePrivate;

/*!
 * \brief The ITechDevice class
 *
 * The class implement base functions for products from
 * JuYing(http://www.juyingele.com.cn/)
 *
 */
class IDEVCTRLIBSHARED_EXPORT ITechDevice : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ITechDevice)
public:
    enum MsgType {
        INVALID     = 0,
        CURRENT,
        VOLTAGE,
        OTHERS
    };

    explicit ITechDevice(QString portName, int baudRate, QObject *parent = Q_NULLPTR);
    ~ITechDevice();

    //for cmds which need source a response
    void devSendCmd(QByteArray &cmd, MsgType type);

    //for cmds which do not need a response
    void devSendCmd(QByteArray &cmd);

    void connectToDevice();
    void disConnectDevice();
    bool isConnected();

signals:
    void reponseValue(double reply, MsgType type);
    void reponseInfo(QString info, MsgType type);
protected:
    ITechDevice(ITechDevicePrivate &dd, QObject *parent = Q_NULLPTR);

private:
    ITechDevicePrivate * const d_ptr;
    Q_DISABLE_COPY(ITechDevice)
};

#endif // ITECHDEVICE_H
