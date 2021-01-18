#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbEXTENDEDDATARECORD.h"

namespace vector {
namespace cdd {

CDDDbEXTENDEDDATARECORD::CDDDbEXTENDEDDATARECORD()
{
}

CDDDbEXTENDEDDATARECORD::~CDDDbEXTENDEDDATARECORD()
{
}

void CDDDbEXTENDEDDATARECORD::load(const QDomElement &element)
{
    CDDDbEXTENDEDDATARECORDImpl::load(element);
}

} // namespace cdd
} // namespace vector
