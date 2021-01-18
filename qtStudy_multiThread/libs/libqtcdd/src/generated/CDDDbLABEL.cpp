
#include "CDDDbLABEL.h"

namespace vector {
namespace cdd {

CDDDbLABEL::CDDDbLABEL()
{
}

CDDDbLABEL::~CDDDbLABEL()
{
}

void CDDDbLABEL::load(const QDomElement &element)
{
    CDDDbLABELImpl::load(element);
}

} // namespace cdd
} // namespace vector
