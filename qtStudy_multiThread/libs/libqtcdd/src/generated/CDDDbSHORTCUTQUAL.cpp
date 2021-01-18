
#include "CDDDbSHORTCUTQUAL.h"

namespace vector {
namespace cdd {

CDDDbSHORTCUTQUAL::CDDDbSHORTCUTQUAL()
{
}

CDDDbSHORTCUTQUAL::~CDDDbSHORTCUTQUAL()
{
}

void CDDDbSHORTCUTQUAL::load(const QDomElement &element)
{
    CDDDbSHORTCUTQUALImpl::load(element);
}

} // namespace cdd
} // namespace vector
