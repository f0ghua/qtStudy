#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDOMAINDATAPROXYCOMP.h"

namespace vector {
namespace cdd {

CDDDbDOMAINDATAPROXYCOMP::CDDDbDOMAINDATAPROXYCOMP()
{
}

CDDDbDOMAINDATAPROXYCOMP::~CDDDbDOMAINDATAPROXYCOMP()
{
}

void CDDDbDOMAINDATAPROXYCOMP::load(const QDomElement &element)
{
    CDDDbDOMAINDATAPROXYCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
