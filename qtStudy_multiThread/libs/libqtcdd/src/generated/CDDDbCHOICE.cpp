#include "CDDDbTUV.h"

#include "CDDDbCHOICE.h"

namespace vector {
namespace cdd {

CDDDbCHOICE::CDDDbCHOICE()
{
}

CDDDbCHOICE::~CDDDbCHOICE()
{
}

void CDDDbCHOICE::load(const QDomElement &element)
{
    CDDDbCHOICEImpl::load(element);
}

} // namespace cdd
} // namespace vector
