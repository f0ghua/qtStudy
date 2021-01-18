#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSPECIFICSNAPSHOTRECORD.h"

namespace vector {
namespace cdd {

CDDDbSPECIFICSNAPSHOTRECORD::CDDDbSPECIFICSNAPSHOTRECORD()
{
}

CDDDbSPECIFICSNAPSHOTRECORD::~CDDDbSPECIFICSNAPSHOTRECORD()
{
}

void CDDDbSPECIFICSNAPSHOTRECORD::load(const QDomElement &element)
{
    CDDDbSPECIFICSNAPSHOTRECORDImpl::load(element);
}

} // namespace cdd
} // namespace vector
