#include "CDDDbTUV.h"

#include "CDDDbADDINFO.h"

namespace vector {
namespace cdd {

CDDDbADDINFO::CDDDbADDINFO()
{
}

CDDDbADDINFO::~CDDDbADDINFO()
{
}

void CDDDbADDINFO::load(const QDomElement &element)
{
    CDDDbADDINFOImpl::load(element);
}

} // namespace cdd
} // namespace vector
