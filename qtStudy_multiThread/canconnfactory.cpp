#include "canconnfactory.h"
#include "ftusbbackend.h"

CANConnection *CANConnFactory::create(QString portName)
{
    return new FTUSBBackend(portName);
}
