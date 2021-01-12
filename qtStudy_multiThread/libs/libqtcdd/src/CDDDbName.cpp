#include "CDDLog.h"
#include "CDDDbName.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbName::CDDDbName()
{
}

CDDDbName::~CDDDbName()
{

}

void CDDDbName::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbName::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "TUV") {
            auto tuv = QSharedPointer<CDDDbTuv>::create();
            tuv->load(childElement);

            m_tuvs.insert(tuv->m_lang, tuv);
        }

        child = child.nextSibling();
    }
}

QString CDDDbName::getValue() const
{
    if (m_tuvs.contains(CDDDbTuv::ATTR_V_ENUS)) {
        return m_tuvs.value(CDDDbTuv::ATTR_V_ENUS)->m_value;
    }
    return QString();
}

} // namespace cdd
} // namespace vector
