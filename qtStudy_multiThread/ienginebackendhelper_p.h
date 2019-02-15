#ifndef IENGINEBACKENDHELPER_P_H
#define IENGINEBACKENDHELPER_P_H

#include "ienginebackend_p.h"

class IEngineBackEndHelper;
class QTcpSocket;

class IEngineBackEndHelperPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(IEngineBackEndHelper)
public:
    enum WStatus {
        eIdle = 0,
        eSocketConnected,
        eClientConnected,
        eDeviceConnected
    };

    IEngineBackEndHelperPrivate(IEngineBackEndHelper *parent);
    virtual ~IEngineBackEndHelperPrivate();
    QStringList availablePorts();
    void sendCommand(COMMAND command, const void *pdata, int plen);
    bool isSockConnected() const {return (m_wStatus >= eSocketConnected);}
    void setWStatus(WStatus v) {m_wStatus = v;}
    bool connectToServer();
    void processResponse(COMMAND_DATA_PACKET *commandData);
    void processRequseDevices(QString s);

    IEngineBackEndHelper * const q_ptr;
    QTcpSocket *m_socket = NULL;
    WStatus m_wStatus = eIdle;
    QStringList m_devList;
    QByteArray m_receivedData;

public slots:
    void handleReceivedData();

signals:
    void portsChanged();
};

#endif // WIZBUSOCKETHELPER_P_H
