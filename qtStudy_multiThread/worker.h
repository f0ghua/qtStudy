#ifndef WORKER_H
#define WORKER_H

#include "busframe.h"

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void frameCatched(const BusFrame &frame);

public slots:
    void run();
    void handle_loadFile(const QString &filePath);

private:
    bool loadBinLogFile(const QString &fileName);
};

#endif // WORKER_H
