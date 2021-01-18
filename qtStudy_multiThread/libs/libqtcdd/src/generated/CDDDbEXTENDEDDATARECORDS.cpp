#include "CDDDbEXTENDEDDATARECORD.h"

#include "CDDDbEXTENDEDDATARECORDS.h"

namespace vector {
namespace cdd {

CDDDbEXTENDEDDATARECORDS::CDDDbEXTENDEDDATARECORDS()
{
}

CDDDbEXTENDEDDATARECORDS::~CDDDbEXTENDEDDATARECORDS()
{
}

void CDDDbEXTENDEDDATARECORDS::load(const QDomElement &element)
{
    CDDDbEXTENDEDDATARECORDSImpl::load(element);
}

} // namespace cdd
} // namespace vector
