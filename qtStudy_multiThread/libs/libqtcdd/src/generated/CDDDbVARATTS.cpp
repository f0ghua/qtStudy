#include "CDDDbENUMDEF.h"

#include "CDDDbVARATTS.h"

namespace vector {
namespace cdd {

CDDDbVARATTS::CDDDbVARATTS()
{
}

CDDDbVARATTS::~CDDDbVARATTS()
{
}

void CDDDbVARATTS::load(const QDomElement &element)
{
    CDDDbVARATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
