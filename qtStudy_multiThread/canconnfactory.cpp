#include "canconnfactory.h"
#include "ftusbbackend.h"
#include "ienginebackend.h"

CANConnection *CANConnFactory::create(QString portName)
{
    //return new FTUSBBackend(portName);
    return new IEngineBackend(portName);
}
