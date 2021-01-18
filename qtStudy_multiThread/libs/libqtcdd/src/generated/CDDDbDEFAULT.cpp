#include "CDDDbTUV.h"

#include "CDDDbDEFAULT.h"

namespace vector {
namespace cdd {

CDDDbDEFAULT::CDDDbDEFAULT()
{
}

CDDDbDEFAULT::~CDDDbDEFAULT()
{
}

void CDDDbDEFAULT::load(const QDomElement &element)
{
    CDDDbDEFAULTImpl::load(element);
}

} // namespace cdd
} // namespace vector
