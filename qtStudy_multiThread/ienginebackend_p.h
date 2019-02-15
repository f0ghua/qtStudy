#ifndef IENGINEBACKEND_P_H
#define IENGINEBACKEND_P_H

#include "ienginebackend.h"

#include <QByteArray>
#include <QTcpSocket>

typedef enum
{
    CLIENT_CONNECT          = 0,
    CLIENT_DISCONNECT       = 1,
    CLIENT_KEEPALIVE        = 2,
    REQUEST_DEVICES         = 3,
    CONNECT_TO_DEVICE       = 4,
    DISCONNECT_FROM_DEVICE  = 5,
    DEVICE_DATA             = 6,
    REQUEST_VERSION         = 7,
    DEVICE_LIST_CHANGED     = 8,
    DEVICE_RAW_DATA         = 9,
    OPEN_ALL_DEVICES        = 10,
    CLOSE_ALL_DEVICES       = 11,
    OPEN_DEVICE_BY_NAME     = 12,
    CLOSE_DEVICE_BY_NAME    = 13,
    OPEN_DEVICE_BY_ID       = 14,
    CLOSE_DEVICE_BY_ID      = 15,
    AM_I_FIRST              = 16,
    SET_FILTER              = 17,
    CLOSE_FILTER            = 18,
    REQUEST_FILTERS         = 19,
    GLOBAL_ENABLE_FILTERS   = 20,
    FTDI_DATA               = 21,
    FTDI_DATA_R             = 22,
    CREATE_VS               = 23,
    DESTROY_VS              = 24,
    UPDATE_TIMESTAMP        = 25
} COMMAND;

typedef struct
{
    quint32 size;
    quint8 command;
    char data[0];
}__attribute__((packed)) COMMAND_DATA_PACKET;

typedef struct
{
    qint32 devId;
    quint32 size;
    char data[0];
}__attribute__((packed)) DEVICE_DATA_PACKET;

class IEngineBackendPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(IEngineBackend)
public:
    enum WStatus {
        eIdle = 0,
        eSocketConnected,
        eClientConnected,
        eDeviceConnected
    };

    IEngineBackendPrivate(IEngineBackend *parent);
    virtual ~IEngineBackendPrivate();
    QStringList availablePorts();
    void sendCommand(COMMAND command, const void *pdata, int plen);
    bool sendData(COMMAND command, const void *pdata, int plen);
    bool isSockConnected() const {return (m_wStatus.load() >= eSocketConnected);}
    void setWStatus(WStatus v) {m_wStatus.store(v);}
    bool connectToServer();
    bool connectDevice(const QString &devName);
    bool disconnectDevice();
    void processResponse(COMMAND_DATA_PACKET *commandData);
    void processRequseDevices(QString s);
    void processConnectToDevice(const char *data);
    void processDeviceData(DEVICE_DATA_PACKET *pDeviceData);
    bool handleFullData(const QByteArray &block);
    void open();
    void close();

    IEngineBackend * const q_ptr;
    QTcpSocket *m_socket = NULL;
    QAtomicInt m_wStatus;
    QStringList m_devList;
    qint32 m_connectedDeviceId = -1;
    QByteArray m_receivedData;
    QString m_remoteIp = "127.0.0.1";
    int m_remotePort = 8000;

public slots:
    void handleReceivedData();
    void handleSockDisconnected();

signals:
    void portsChanged();
};

#endif // IENGINEBACKEND_P_H
