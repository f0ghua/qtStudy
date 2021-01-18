#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMP.h"

#include "CDDDbUNSUPPSRVNEG.h"

namespace vector {
namespace cdd {

CDDDbUNSUPPSRVNEG::CDDDbUNSUPPSRVNEG()
{
}

CDDDbUNSUPPSRVNEG::~CDDDbUNSUPPSRVNEG()
{
}

void CDDDbUNSUPPSRVNEG::load(const QDomElement &element)
{
    CDDDbUNSUPPSRVNEGImpl::load(element);
}

} // namespace cdd
} // namespace vector
