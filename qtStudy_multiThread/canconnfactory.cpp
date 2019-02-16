#include "canconnfactory.h"
#include "ftusbbackend.h"
#include "ienginebackend.h"

CANConnection *CANConnFactory::create(QString portName)
{
#ifdef USE_FTUSBBACKEND
    return new FTUSBBackend(portName);
#else
    return new IEngineBackend(portName);
#endif
}
