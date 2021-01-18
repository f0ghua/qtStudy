
#include "CDDDbENUMImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbENUMImpl::CDDDbENUMImpl()
{
}

CDDDbENUMImpl::~CDDDbENUMImpl()
{
}

void CDDDbENUMImpl::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector
