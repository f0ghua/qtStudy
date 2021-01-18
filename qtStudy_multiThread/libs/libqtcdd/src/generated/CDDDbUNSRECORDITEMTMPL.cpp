#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbUNSRECORDITEMTMPL.h"

namespace vector {
namespace cdd {

CDDDbUNSRECORDITEMTMPL::CDDDbUNSRECORDITEMTMPL()
{
}

CDDDbUNSRECORDITEMTMPL::~CDDDbUNSRECORDITEMTMPL()
{
}

void CDDDbUNSRECORDITEMTMPL::load(const QDomElement &element)
{
    CDDDbUNSRECORDITEMTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
