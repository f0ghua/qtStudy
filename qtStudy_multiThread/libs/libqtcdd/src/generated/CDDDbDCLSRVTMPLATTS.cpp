#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbDCLSRVTMPLATTS.h"

namespace vector {
namespace cdd {

CDDDbDCLSRVTMPLATTS::CDDDbDCLSRVTMPLATTS()
{
}

CDDDbDCLSRVTMPLATTS::~CDDDbDCLSRVTMPLATTS()
{
}

void CDDDbDCLSRVTMPLATTS::load(const QDomElement &element)
{
    CDDDbDCLSRVTMPLATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
