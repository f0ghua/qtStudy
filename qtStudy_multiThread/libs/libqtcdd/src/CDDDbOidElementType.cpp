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
    CDDDbIdElementType::load(element);

    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
}

} // namespace cdd
} // namespace vector
