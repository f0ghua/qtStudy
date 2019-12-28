#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message {
public:
    quint32 id;
    QByteArray data;
};

#endif // MESSAGE_H
