
#include "CDDDbUNS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNS::CDDDbUNS()
{
}

CDDDbUNS::~CDDDbUNS()
{
}

void CDDDbUNS::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector
