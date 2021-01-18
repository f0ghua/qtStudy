#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLECOMPCONT.h"

#include "CDDDbCONTENTCOMP.h"

namespace vector {
namespace cdd {

CDDDbCONTENTCOMP::CDDDbCONTENTCOMP()
{
}

CDDDbCONTENTCOMP::~CDDDbCONTENTCOMP()
{
}

void CDDDbCONTENTCOMP::load(const QDomElement &element)
{
    CDDDbCONTENTCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
