#include "CDDDbFC.h"

#include "CDDDbPARA.h"

namespace vector {
namespace cdd {

CDDDbPARA::CDDDbPARA()
{
}

CDDDbPARA::~CDDDbPARA()
{
}

void CDDDbPARA::load(const QDomElement &element)
{
    CDDDbPARAImpl::load(element);
}

} // namespace cdd
} // namespace vector
