#include "CDDDbTUV.h"

#include "CDDDbSTRING.h"

namespace vector {
namespace cdd {

CDDDbSTRING::CDDDbSTRING()
{
}

CDDDbSTRING::~CDDDbSTRING()
{
}

void CDDDbSTRING::load(const QDomElement &element)
{
    CDDDbSTRINGImpl::load(element);
}

} // namespace cdd
} // namespace vector
