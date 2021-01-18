#include "CDDDbDCLTMPL.h"

#include "CDDDbDCLTMPLS.h"

namespace vector {
namespace cdd {

CDDDbDCLTMPLS::CDDDbDCLTMPLS()
{
}

CDDDbDCLTMPLS::~CDDDbDCLTMPLS()
{
}

void CDDDbDCLTMPLS::load(const QDomElement &element)
{
    CDDDbDCLTMPLSImpl::load(element);
}

} // namespace cdd
} // namespace vector
