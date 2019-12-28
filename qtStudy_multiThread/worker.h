#ifndef WORKER_H
#define WORKER_H

#include "message.h"

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void sendMessage(const Message &msg);

public slots:
    void run();
};

#endif // WORKER_H
