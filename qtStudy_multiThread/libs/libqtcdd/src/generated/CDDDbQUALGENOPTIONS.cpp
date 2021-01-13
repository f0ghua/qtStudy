
#include "CDDDbQUALGENOPTIONS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbQUALGENOPTIONS::CDDDbQUALGENOPTIONS()
{
}

CDDDbQUALGENOPTIONS::~CDDDbQUALGENOPTIONS()
{
}

void CDDDbQUALGENOPTIONS::load(const QDomElement &element)
{
    m_case = element.attribute("case");
    m_maxLen = element.attribute("maxLen");
    m_minLen = element.attribute("minLen");

}

} // namespace cdd
} // namespace vector
