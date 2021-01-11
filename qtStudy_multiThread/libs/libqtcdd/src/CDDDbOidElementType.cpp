#include "CDDLog.h"
#include "CDDDbOidElementType.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbOidElementType::CDDDbOidElementType()
    : CDDDbIdElementType()
{
}

CDDDbOidElementType::~CDDDbOidElementType()
{

}

void CDDDbOidElementType::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    CDDDbIdElementType::load(element);
}

} // namespace cdd
} // namespace vector
