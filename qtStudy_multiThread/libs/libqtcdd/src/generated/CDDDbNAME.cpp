#include "CDDDbTUV.h"

#include "CDDDbNAME.h"

namespace vector {
namespace cdd {

CDDDbNAME::CDDDbNAME()
{
}

CDDDbNAME::~CDDDbNAME()
{
}

void CDDDbNAME::load(const QDomElement &element)
{
    CDDDbNAMEImpl::load(element);
}

QString CDDDbNAME::getValue() const
{
    if (m_elTuvs.contains(CDDDbTUV::ATTR_V_ENUS)) {
        return m_elTuvs.value(CDDDbTUV::ATTR_V_ENUS)->m_text;
    }
    return QString();
}

} // namespace cdd
} // namespace vector
