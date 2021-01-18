#include "CDDDbSTATEGROUP.h"

#include "CDDDbSTATEGROUPS.h"

namespace vector {
namespace cdd {

CDDDbSTATEGROUPS::CDDDbSTATEGROUPS()
{
}

CDDDbSTATEGROUPS::~CDDDbSTATEGROUPS()
{
}

void CDDDbSTATEGROUPS::load(const QDomElement &element)
{
    CDDDbSTATEGROUPSImpl::load(element);
}

} // namespace cdd
} // namespace vector
