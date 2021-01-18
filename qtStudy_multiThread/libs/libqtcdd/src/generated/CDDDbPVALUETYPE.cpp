#include "CDDDbUNIT.h"

#include "CDDDbPVALUETYPE.h"

namespace vector {
namespace cdd {

CDDDbPVALUETYPE::CDDDbPVALUETYPE()
{
}

CDDDbPVALUETYPE::~CDDDbPVALUETYPE()
{
}

void CDDDbPVALUETYPE::load(const QDomElement &element)
{
    CDDDbPVALUETYPEImpl::load(element);
}

} // namespace cdd
} // namespace vector
