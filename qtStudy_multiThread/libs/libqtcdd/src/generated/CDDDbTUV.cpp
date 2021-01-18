#include "CDDDbTUV.h"

namespace vector {
namespace cdd {

QString CDDDbTUV::ATTR_T_LANG = QStringLiteral("xml:lang");
QString CDDDbTUV::ATTR_V_ENUS = QStringLiteral("en-US");

CDDDbTUV::CDDDbTUV()
{
}

CDDDbTUV::~CDDDbTUV()
{
}

void CDDDbTUV::load(const QDomElement &element)
{
    CDDDbTUVImpl::load(element);
}

} // namespace cdd
} // namespace vector
