
#include "CDDDbSTATICVALUE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATICVALUE::CDDDbSTATICVALUE()
{
}

CDDDbSTATICVALUE::~CDDDbSTATICVALUE()
{
}

void CDDDbSTATICVALUE::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_shstaticref = element.attribute("shstaticref");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector
