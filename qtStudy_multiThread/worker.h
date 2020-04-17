#ifndef WORKER_H
#define WORKER_H

#include "busframe.h"
#include "tracemodel.h"

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(TraceModel *model, QObject *parent = nullptr);

signals:
    void frameCatched(const BusFrame &frame);

public slots:
    void run();
    void handle_loadFile(const QString &filePath);

private:
    bool loadBinLogFile(const QString &fileName);

    TraceModel *m_model;
};

#endif // WORKER_H
