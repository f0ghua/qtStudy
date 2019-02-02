#ifndef CANCONNFACTORY_H
#define CANCONNFACTORY_H

#include "canconnection.h"

class CANConnFactory
{
public:
    static CANConnection* create(QString portName);
};

#endif // CANNCONNFACTORY_H
