#include "CDDDbTARGETGROUP.h"

#include "CDDDbTARGETGROUPS.h"

namespace vector {
namespace cdd {

CDDDbTARGETGROUPS::CDDDbTARGETGROUPS()
{
}

CDDDbTARGETGROUPS::~CDDDbTARGETGROUPS()
{
}

void CDDDbTARGETGROUPS::load(const QDomElement &element)
{
    CDDDbTARGETGROUPSImpl::load(element);
}

} // namespace cdd
} // namespace vector
