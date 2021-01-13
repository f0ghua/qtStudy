
#include "CDDDbENUM.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbENUM::CDDDbENUM()
{
}

CDDDbENUM::~CDDDbENUM()
{
}

void CDDDbENUM::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector
