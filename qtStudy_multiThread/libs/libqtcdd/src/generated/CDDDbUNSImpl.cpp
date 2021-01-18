
#include "CDDDbUNSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNSImpl::CDDDbUNSImpl()
{
}

CDDDbUNSImpl::~CDDDbUNSImpl()
{
}

void CDDDbUNSImpl::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector
