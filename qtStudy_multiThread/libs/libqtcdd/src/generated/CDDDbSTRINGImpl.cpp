#include "CDDDbTUV.h"

#include "CDDDbSTRINGImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRINGImpl::CDDDbSTRINGImpl()
    : CDDDbNAMEImpl()
{
}

CDDDbSTRINGImpl::~CDDDbSTRINGImpl()
{
}

void CDDDbSTRINGImpl::load(const QDomElement &element)
{
    CDDDbNAMEImpl::load(element);
}

} // namespace cdd
} // namespace vector
