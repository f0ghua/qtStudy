
#include "CDDDbUNIT.h"

namespace vector {
namespace cdd {

CDDDbUNIT::CDDDbUNIT()
{
}

CDDDbUNIT::~CDDDbUNIT()
{
}

void CDDDbUNIT::load(const QDomElement &element)
{
    CDDDbUNITImpl::load(element);
}

} // namespace cdd
} // namespace vector
