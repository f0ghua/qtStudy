#include "CDDDbENUMDEF.h"

#include "CDDDbDIAGCLASSATTS.h"

namespace vector {
namespace cdd {

CDDDbDIAGCLASSATTS::CDDDbDIAGCLASSATTS()
{
}

CDDDbDIAGCLASSATTS::~CDDDbDIAGCLASSATTS()
{
}

void CDDDbDIAGCLASSATTS::load(const QDomElement &element)
{
    CDDDbDIAGCLASSATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
