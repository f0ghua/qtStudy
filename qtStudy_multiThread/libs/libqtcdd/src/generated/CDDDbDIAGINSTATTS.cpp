#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbDIAGINSTATTS.h"

namespace vector {
namespace cdd {

CDDDbDIAGINSTATTS::CDDDbDIAGINSTATTS()
{
}

CDDDbDIAGINSTATTS::~CDDDbDIAGINSTATTS()
{
}

void CDDDbDIAGINSTATTS::load(const QDomElement &element)
{
    CDDDbDIAGINSTATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
