#ifndef DEVMANAGER_H
#define DEVMANAGER_H

#include <QObject>
#include <QVector>

class DevManagerPrivate;

class DevMgrReply : public QObject
{
    Q_OBJECT

public:
    DevMgrReply(QObject *parent = nullptr) {};
    DevMgrReply(const DevMgrReply&);
    virtual ~DevMgrReply(){};
    inline QVector<double> values() const { return m_values; }
    inline void setValues(const QVector<double> &newValues)
    {
        m_values = newValues;
    }

signals:
    void finished();

private:
    bool isError = false;
    QVector<double> m_values;
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
    DevMgrReply *relayGetStatesEx(int id);

signals:
    void eloadRegValueUpdate(const QString &address, int devid, int reg, double value);
    void devMgrReady();

protected:

private:
    DevManagerPrivate * const d_ptr;
    Q_DISABLE_COPY(DevManager)
};

#endif // DEVMANAGER_H
