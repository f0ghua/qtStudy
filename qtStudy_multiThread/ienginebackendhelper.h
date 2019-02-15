#ifndef IENGINEBACKENDHELPER_H
#define IENGINEBACKENDHELPER_H

#include <QObject>

class IEngineBackEndHelperPrivate;

class IEngineBackEndHelper : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(IEngineBackEndHelper)
public:
    explicit IEngineBackEndHelper(QObject *parent = nullptr);
    ~IEngineBackEndHelper();
    QStringList availablePorts() const;

private:
    IEngineBackEndHelperPrivate * const d_ptr;
};

#endif // WIZBUSOCKETHELPER_H
