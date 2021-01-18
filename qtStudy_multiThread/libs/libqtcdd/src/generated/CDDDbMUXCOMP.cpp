#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbMUXCOMP.h"

namespace vector {
namespace cdd {

CDDDbMUXCOMP::CDDDbMUXCOMP()
{
}

CDDDbMUXCOMP::~CDDDbMUXCOMP()
{
}

void CDDDbMUXCOMP::load(const QDomElement &element)
{
    CDDDbMUXCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
