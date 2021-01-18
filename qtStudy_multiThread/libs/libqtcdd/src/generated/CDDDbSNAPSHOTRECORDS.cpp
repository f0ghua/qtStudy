#include "CDDDbSPECIFICSNAPSHOTRECORD.h"

#include "CDDDbSNAPSHOTRECORDS.h"

namespace vector {
namespace cdd {

CDDDbSNAPSHOTRECORDS::CDDDbSNAPSHOTRECORDS()
{
}

CDDDbSNAPSHOTRECORDS::~CDDDbSNAPSHOTRECORDS()
{
}

void CDDDbSNAPSHOTRECORDS::load(const QDomElement &element)
{
    CDDDbSNAPSHOTRECORDSImpl::load(element);
}

} // namespace cdd
} // namespace vector
