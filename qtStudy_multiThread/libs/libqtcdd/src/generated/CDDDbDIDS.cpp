#include "CDDDbDID.h"

#include "CDDDbDIDS.h"

namespace vector {
namespace cdd {

CDDDbDIDS::CDDDbDIDS()
{
}

CDDDbDIDS::~CDDDbDIDS()
{
}

void CDDDbDIDS::load(const QDomElement &element)
{
    CDDDbDIDSImpl::load(element);
}

} // namespace cdd
} // namespace vector
