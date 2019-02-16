#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#define WKER_WAITLOOP   100000

class QTimer;
class CANConnection;

class Worker : public QObject
{
    Q_OBJECT
public:
    enum WorkingState {
        eIDLE,
        eBENCHMARKING
    };

    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void msgDump(const QString &msg);

public slots:
    void run();
    void onWorkStop();
    void createConnection(const QString &devName);
    void startBenchmark();
    void stopBenchmark();
    void handleTimeout();
    void setWaitLoop(quint32 loop);

private:
    QTimer *m_timer;
    CANConnection *m_canConnection = NULL;
    bool m_isRunning = true;
    WorkingState m_workingState = eIDLE;
    quint32 m_waitLoop = WKER_WAITLOOP;
};

#endif // WORKER_H
