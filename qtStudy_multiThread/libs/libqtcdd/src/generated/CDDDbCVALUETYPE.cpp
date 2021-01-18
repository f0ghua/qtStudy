#include "CDDDbUNIT.h"

#include "CDDDbCVALUETYPE.h"

namespace vector {
namespace cdd {

CDDDbCVALUETYPE::CDDDbCVALUETYPE()
{
}

CDDDbCVALUETYPE::~CDDDbCVALUETYPE()
{
}

void CDDDbCVALUETYPE::load(const QDomElement &element)
{
    CDDDbCVALUETYPEImpl::load(element);
}

} // namespace cdd
} // namespace vector
