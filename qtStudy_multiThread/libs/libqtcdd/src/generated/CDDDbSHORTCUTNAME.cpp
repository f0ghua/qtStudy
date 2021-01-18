#include "CDDDbTUV.h"

#include "CDDDbSHORTCUTNAME.h"

namespace vector {
namespace cdd {

CDDDbSHORTCUTNAME::CDDDbSHORTCUTNAME()
{
}

CDDDbSHORTCUTNAME::~CDDDbSHORTCUTNAME()
{
}

void CDDDbSHORTCUTNAME::load(const QDomElement &element)
{
    CDDDbSHORTCUTNAMEImpl::load(element);
}

} // namespace cdd
} // namespace vector
