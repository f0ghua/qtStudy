#ifndef DEVMANAGER_H
#define DEVMANAGER_H

#include <QObject>

class DevManagerPrivate;

class DevMgrReply : public QObject
{
    Q_OBJECT

public:
    DevMgrReply(QObject *parent = nullptr) {};
    DevMgrReply(const DevMgrReply&);
    virtual ~DevMgrReply(){};

signals:
    void finished();

private:
    bool isError = false;
};

Q_DECLARE_METATYPE(DevMgrReply);

class DevManager : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(DevManager)
public:
    explicit DevManager(QObject *parent = Q_NULLPTR);
    ~DevManager();
    int getEloadIdbyAddress(const QString &addressPair);

public slots:
    void run();
    void eloadClearAllConfigedCurrent();
    void eloadSetConfigedCurrent(int id, int channel, double value);
    void eloadGetCurrent(int id, int channel);
    DevMgrReply *eloadSetConfigedCurrentAsyncEx(int id, int channel, double value);

signals:
    void eloadRegValueUpdate(const QString &address, int devid, int reg, double value);
    void devMgrReady();

protected:

private:
    DevManagerPrivate * const d_ptr;
    Q_DISABLE_COPY(DevManager)
};

#endif // DEVMANAGER_H
