#include "CDDDbCOMMONSNAPSHOTDATAPOOL.h"
#include "CDDDbEXTENDEDDATARECORDS.h"
#include "CDDDbSNAPSHOTRECORDS.h"

#include "CDDDbFAULTMEMORY.h"

namespace vector {
namespace cdd {

CDDDbFAULTMEMORY::CDDDbFAULTMEMORY()
{
}

CDDDbFAULTMEMORY::~CDDDbFAULTMEMORY()
{
}

void CDDDbFAULTMEMORY::load(const QDomElement &element)
{
    CDDDbFAULTMEMORYImpl::load(element);
}

} // namespace cdd
} // namespace vector
