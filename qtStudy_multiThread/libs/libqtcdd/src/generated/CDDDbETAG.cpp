#include "CDDDbTUV.h"

#include "CDDDbETAG.h"

namespace vector {
namespace cdd {

CDDDbETAG::CDDDbETAG()
{
}

CDDDbETAG::~CDDDbETAG()
{
}

void CDDDbETAG::load(const QDomElement &element)
{
    CDDDbETAGImpl::load(element);
}

QString CDDDbETAG::getValue() const
{
    if (m_elTuvs.contains(CDDDbTUV::ATTR_V_ENUS)) {
        return m_elTuvs.value(CDDDbTUV::ATTR_V_ENUS)->m_text;
    }
    return QString();
}

} // namespace cdd
} // namespace vector
