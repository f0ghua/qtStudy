#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class DevManager;

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(DevManager *devMgr, QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    int el_setConfigedCurrentBlock(int id, int channel, double value);
    void inline eloadSetConfigedCurrent(int id, int channel, double value);
    void inline eloadGetCurrent(int id, int channel);
    int rl_getAllStatesBlock(int id);

    DevManager *m_devMgr = NULL;
};

#endif // WORKER_H
