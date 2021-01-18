#include "CDDDbNAME.h"
#include "CDDDbPROXYCOMPREF.h"
#include "CDDDbQUAL.h"

#include "CDDDbSHPROXY.h"

namespace vector {
namespace cdd {

CDDDbSHPROXY::CDDDbSHPROXY()
{
}

CDDDbSHPROXY::~CDDDbSHPROXY()
{
}

void CDDDbSHPROXY::load(const QDomElement &element)
{
    CDDDbSHPROXYImpl::load(element);
}

} // namespace cdd
} // namespace vector
