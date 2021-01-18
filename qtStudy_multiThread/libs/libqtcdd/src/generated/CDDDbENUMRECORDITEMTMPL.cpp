#include "CDDDbDESC.h"
#include "CDDDbETAG.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbENUMRECORDITEMTMPL.h"

namespace vector {
namespace cdd {

CDDDbENUMRECORDITEMTMPL::CDDDbENUMRECORDITEMTMPL()
{
}

CDDDbENUMRECORDITEMTMPL::~CDDDbENUMRECORDITEMTMPL()
{
}

void CDDDbENUMRECORDITEMTMPL::load(const QDomElement &element)
{
    CDDDbENUMRECORDITEMTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
