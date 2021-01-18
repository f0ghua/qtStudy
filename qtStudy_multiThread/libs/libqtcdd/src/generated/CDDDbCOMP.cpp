
#include "CDDDbCOMP.h"

namespace vector {
namespace cdd {

CDDDbCOMP::CDDDbCOMP()
{
}

CDDDbCOMP::~CDDDbCOMP()
{
}

void CDDDbCOMP::load(const QDomElement &element)
{
    CDDDbCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector
