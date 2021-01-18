#include "CDDDbCHOICE.h"
#include "CDDDbDEFAULT.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbTRRECORDITEMTMPL.h"

namespace vector {
namespace cdd {

CDDDbTRRECORDITEMTMPL::CDDDbTRRECORDITEMTMPL()
{
}

CDDDbTRRECORDITEMTMPL::~CDDDbTRRECORDITEMTMPL()
{
}

void CDDDbTRRECORDITEMTMPL::load(const QDomElement &element)
{
    CDDDbTRRECORDITEMTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
