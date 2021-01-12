#include "CDDLog.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

QString CDDDbTuv::ATTR_T_LANG = QStringLiteral("xml:lang");
QString CDDDbTuv::ATTR_V_ENUS = QStringLiteral("en-US");

CDDDbTuv::CDDDbTuv()
{
}

CDDDbTuv::~CDDDbTuv()
{

}

void CDDDbTuv::load(const QDomElement &element)
{
    m_lang = element.attribute(ATTR_T_LANG);
    m_value = element.text();
}

} // namespace cdd
} // namespace vector
