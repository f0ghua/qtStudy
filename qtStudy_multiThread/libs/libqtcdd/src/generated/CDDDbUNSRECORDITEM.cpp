
#include "CDDDbUNSRECORDITEM.h"

namespace vector {
namespace cdd {

CDDDbUNSRECORDITEM::CDDDbUNSRECORDITEM()
{
}

CDDDbUNSRECORDITEM::~CDDDbUNSRECORDITEM()
{
}

void CDDDbUNSRECORDITEM::load(const QDomElement &element)
{
    CDDDbUNSRECORDITEMImpl::load(element);
}

} // namespace cdd
} // namespace vector
