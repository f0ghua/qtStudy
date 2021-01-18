#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbECUATTS.h"

namespace vector {
namespace cdd {

CDDDbECUATTS::CDDDbECUATTS()
{
}

CDDDbECUATTS::~CDDDbECUATTS()
{
}

void CDDDbECUATTS::load(const QDomElement &element)
{
    CDDDbECUATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
