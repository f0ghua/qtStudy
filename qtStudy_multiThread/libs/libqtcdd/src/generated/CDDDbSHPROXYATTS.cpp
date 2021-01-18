#include "CDDDbCSTRDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbSHPROXYATTS.h"

namespace vector {
namespace cdd {

CDDDbSHPROXYATTS::CDDDbSHPROXYATTS()
{
}

CDDDbSHPROXYATTS::~CDDDbSHPROXYATTS()
{
}

void CDDDbSHPROXYATTS::load(const QDomElement &element)
{
    CDDDbSHPROXYATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector
