#include "CDDLog.h"
#include "CDDDbTuvedType.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTuvedType::CDDDbTuvedType()
{
}

CDDDbTuvedType::~CDDDbTuvedType()
{

}

void CDDDbTuvedType::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbEnTuvType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "TUV") {
            auto tuv = QSharedPointer<CDDDbTuv>::create();
            tuv->load(childElement);

            m_tuvs.insert(tuv->m_lang, tuv);
        }

        child = child.nextSibling();
    }
}

QString CDDDbTuvedType::getText() const
{
    if (m_tuvs.contains(CDDDbTuv::ATTR_V_ENUS)) {
        return m_tuvs.value(CDDDbTuv::ATTR_V_ENUS)->m_value;
    }
    return QString();
}

} // namespace cdd
} // namespace vector
