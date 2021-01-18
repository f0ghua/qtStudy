#include "CDDDbTUV.h"

#include "CDDDbETAGImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbETAGImpl::CDDDbETAGImpl()
    : CDDDbNAMEImpl()
{
}

CDDDbETAGImpl::~CDDDbETAGImpl()
{
}

void CDDDbETAGImpl::load(const QDomElement &element)
{
    CDDDbNAMEImpl::load(element);

    m_v = element.attribute("v"); 
}

} // namespace cdd
} // namespace vector
