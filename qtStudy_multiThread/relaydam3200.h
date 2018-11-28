#ifndef RELAYDAM3200_H
#define RELAYDAM3200_H

#include "jydevice.h"

class RelayDam3200 : public JYDevice
{
public:
    RelayDam3200(QObject *parent = Q_NULLPTR, int circuitNumber = 32);
    RelayDam3200(QString address, int port, QObject *parent = Q_NULLPTR, int circuitNumber = 32);

    void switchOn(int circuit);
    void switchOff(int circuit);
    void setAllOn();
    void setAllOff();
    void setStates(int circuit, const QList<bool> &stateList);
    QModbusReply *getStatesAsyncEx();

private:
    int m_circuitNumber;
};

#endif // RELAYDAM3200_H
