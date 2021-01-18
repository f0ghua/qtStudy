#include "CDDDbENUMDEF.h"

#include "CDDDbJOBCNRATTS.h"

namespace vector {
namespace cdd {

CDDDbJOBCNRATTS::CDDDbJOBCNRATTS()
{
}

CDDDbJOBCNRATTS::~CDDDbJOBCNRATTS()
{
}

void CDDDbJOBCNRATTS::load(const QDomElement &element)
{
    CDDDbJOBCNRATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
