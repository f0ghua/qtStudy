#include "CDDDbTuvedType.h"
#include "CDDLog.h"
#include "CDDDbEtag.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEtag::CDDDbEtag()
    : CDDDbTuvedType()
{
}

CDDDbEtag::~CDDDbEtag()
{

}

void CDDDbEtag::load(const QDomElement &element)
{
    CDDDbTuvedType::load(element);

    m_value = element.attribute("v").toUInt();
}

} // namespace cdd
} // namespace vector
