#include "CDDDbCVALUETYPE.h"
#include "CDDDbENUMRECORDITEMTMPL.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbTRRECORDITEMTMPL.h"
#include "CDDDbUNSRECORDITEMTMPL.h"

#include "CDDDbRECORDTMPL.h"

namespace vector {
namespace cdd {

CDDDbRECORDTMPL::CDDDbRECORDTMPL()
{
}

CDDDbRECORDTMPL::~CDDDbRECORDTMPL()
{
}

void CDDDbRECORDTMPL::load(const QDomElement &element)
{
    CDDDbRECORDTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
