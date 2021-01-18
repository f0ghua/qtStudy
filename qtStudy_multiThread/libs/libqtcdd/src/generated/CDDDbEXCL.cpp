#include "CDDDbTEXT.h"

#include "CDDDbEXCL.h"

namespace vector {
namespace cdd {

CDDDbEXCL::CDDDbEXCL()
{
}

CDDDbEXCL::~CDDDbEXCL()
{
}

void CDDDbEXCL::load(const QDomElement &element)
{
    CDDDbEXCLImpl::load(element);
}

} // namespace cdd
} // namespace vector
