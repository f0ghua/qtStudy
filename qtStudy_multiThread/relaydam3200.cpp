#include "relaydam3200.h"
#include "commdefine.h"

#include <QVector>
#include <QDebug>

#define TCP_SERVERADDR      0
#define UDP_SERVERADDR      0xFE
#define SERVER_ADDRESS      UDP_SERVERADDR

RelayDam3200::RelayDam3200(QObject *parent, int circuitNumber)
    : JYDevice(parent)
    , m_circuitNumber(circuitNumber)
{

}

RelayDam3200::RelayDam3200(QString address, int port, QObject *parent, int circuitNumber)
    :JYDevice(address, port, parent)
    , m_circuitNumber(circuitNumber)
{

}

void RelayDam3200::switchOn(int circuit)
{
    devWriteRegisterAsync(SERVER_ADDRESS, circuit, 0xFF00);
}

void RelayDam3200::switchOff(int circuit)
{
    devWriteRegisterAsync(SERVER_ADDRESS, circuit, 0x0000);
}

void RelayDam3200::setAllOn()
{
    devWriteMCHexString(SERVER_ADDRESS, "0000002004FFFFFFFF");
}

void RelayDam3200::setAllOff()
{
    devWriteMCHexString(SERVER_ADDRESS, "000000200400000000");
}

void RelayDam3200::setStates(int circuit, const QList<bool> &stateList)
{
    QVector<quint16> values;
    foreach (bool isOn, stateList) {
        values.append(isOn?0xFF00:0x0000);
    }
    if ((values.size() - circuit) > m_circuitNumber) {
        qDebug() << "stateList has too many items";
        return;
    }

    devWriteRegistersAsync(SERVER_ADDRESS, circuit, values);
}

QModbusReply *RelayDam3200::getStatesAsyncEx()
{
    return devReadRegistersAsyncEx(SERVER_ADDRESS, 0, 32);
}
