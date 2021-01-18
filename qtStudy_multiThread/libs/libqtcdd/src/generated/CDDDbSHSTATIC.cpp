#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMPREF.h"

#include "CDDDbSHSTATIC.h"

namespace vector {
namespace cdd {

CDDDbSHSTATIC::CDDDbSHSTATIC()
{
}

CDDDbSHSTATIC::~CDDDbSHSTATIC()
{
}

void CDDDbSHSTATIC::load(const QDomElement &element)
{
    CDDDbSHSTATICImpl::load(element);
}

} // namespace cdd
} // namespace vector
