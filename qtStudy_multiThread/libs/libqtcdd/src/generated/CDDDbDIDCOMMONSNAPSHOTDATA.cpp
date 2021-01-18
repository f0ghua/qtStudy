#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIDCOMMONSNAPSHOTDATA.h"

namespace vector {
namespace cdd {

CDDDbDIDCOMMONSNAPSHOTDATA::CDDDbDIDCOMMONSNAPSHOTDATA()
{
}

CDDDbDIDCOMMONSNAPSHOTDATA::~CDDDbDIDCOMMONSNAPSHOTDATA()
{
}

void CDDDbDIDCOMMONSNAPSHOTDATA::load(const QDomElement &element)
{
    CDDDbDIDCOMMONSNAPSHOTDATAImpl::load(element);
}

} // namespace cdd
} // namespace vector
