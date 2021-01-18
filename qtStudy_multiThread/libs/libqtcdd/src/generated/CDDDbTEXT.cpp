#include "CDDDbTUV.h"

#include "CDDDbTEXT.h"

namespace vector {
namespace cdd {

CDDDbTEXT::CDDDbTEXT()
{
}

CDDDbTEXT::~CDDDbTEXT()
{
}

void CDDDbTEXT::load(const QDomElement &element)
{
    CDDDbTEXTImpl::load(element);
}

} // namespace cdd
} // namespace vector
