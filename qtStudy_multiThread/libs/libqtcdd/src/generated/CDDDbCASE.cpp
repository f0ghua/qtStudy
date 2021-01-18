#include "CDDDbSTRUCTURE.h"

#include "CDDDbCASE.h"

namespace vector {
namespace cdd {

CDDDbCASE::CDDDbCASE()
{
}

CDDDbCASE::~CDDDbCASE()
{
}

void CDDDbCASE::load(const QDomElement &element)
{
    CDDDbCASEImpl::load(element);
}

} // namespace cdd
} // namespace vector
