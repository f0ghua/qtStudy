
#include "CDDDbUNS.h"

namespace vector {
namespace cdd {

CDDDbUNS::CDDDbUNS()
{
}

CDDDbUNS::~CDDDbUNS()
{
}

void CDDDbUNS::load(const QDomElement &element)
{
    CDDDbUNSImpl::load(element);
}

} // namespace cdd
} // namespace vector
