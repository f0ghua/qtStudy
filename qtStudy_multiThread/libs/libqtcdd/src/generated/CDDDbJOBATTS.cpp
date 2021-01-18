#include "CDDDbENUMDEF.h"

#include "CDDDbJOBATTS.h"

namespace vector {
namespace cdd {

CDDDbJOBATTS::CDDDbJOBATTS()
{
}

CDDDbJOBATTS::~CDDDbJOBATTS()
{
}

void CDDDbJOBATTS::load(const QDomElement &element)
{
    CDDDbJOBATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
