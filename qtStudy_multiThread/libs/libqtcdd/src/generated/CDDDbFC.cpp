
#include "CDDDbFC.h"

namespace vector {
namespace cdd {

CDDDbFC::CDDDbFC()
{
}

CDDDbFC::~CDDDbFC()
{
}

void CDDDbFC::load(const QDomElement &element)
{
    CDDDbFCImpl::load(element);
}

} // namespace cdd
} // namespace vector
