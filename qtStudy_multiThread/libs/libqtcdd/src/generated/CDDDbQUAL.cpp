
#include "CDDDbQUAL.h"

namespace vector {
namespace cdd {

CDDDbQUAL::CDDDbQUAL()
{
}

CDDDbQUAL::~CDDDbQUAL()
{
}

void CDDDbQUAL::load(const QDomElement &element)
{
    CDDDbQUALImpl::load(element);
}

} // namespace cdd
} // namespace vector
