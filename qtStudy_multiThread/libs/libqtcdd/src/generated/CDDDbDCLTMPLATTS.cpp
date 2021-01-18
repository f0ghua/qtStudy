#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbDCLTMPLATTS.h"

namespace vector {
namespace cdd {

CDDDbDCLTMPLATTS::CDDDbDCLTMPLATTS()
{
}

CDDDbDCLTMPLATTS::~CDDDbDCLTMPLATTS()
{
}

void CDDDbDCLTMPLATTS::load(const QDomElement &element)
{
    CDDDbDCLTMPLATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
