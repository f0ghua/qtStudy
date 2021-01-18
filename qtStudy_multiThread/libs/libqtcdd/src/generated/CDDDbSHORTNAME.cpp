
#include "CDDDbSHORTNAME.h"

namespace vector {
namespace cdd {

CDDDbSHORTNAME::CDDDbSHORTNAME()
{
}

CDDDbSHORTNAME::~CDDDbSHORTNAME()
{
}

void CDDDbSHORTNAME::load(const QDomElement &element)
{
    CDDDbSHORTNAMEImpl::load(element);
}

} // namespace cdd
} // namespace vector
