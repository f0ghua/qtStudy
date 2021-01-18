#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDCLSRVTMPL.h"

namespace vector {
namespace cdd {

CDDDbDCLSRVTMPL::CDDDbDCLSRVTMPL()
{
}

CDDDbDCLSRVTMPL::~CDDDbDCLSRVTMPL()
{
}

void CDDDbDCLSRVTMPL::load(const QDomElement &element)
{
    CDDDbDCLSRVTMPLImpl::load(element);
}

} // namespace cdd
} // namespace vector
