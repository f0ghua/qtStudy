
#include "CDDDbSTATICVALUE.h"

namespace vector {
namespace cdd {

CDDDbSTATICVALUE::CDDDbSTATICVALUE()
{
}

CDDDbSTATICVALUE::~CDDDbSTATICVALUE()
{
}

void CDDDbSTATICVALUE::load(const QDomElement &element)
{
    CDDDbSTATICVALUEImpl::load(element);
}

} // namespace cdd
} // namespace vector
