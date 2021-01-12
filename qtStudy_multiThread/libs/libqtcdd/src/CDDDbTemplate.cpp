#include "CDDLog.h"
#include "CDDDbTemplate.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTemplate::CDDDbTemplate()
{
}

CDDDbTemplate::~CDDDbTemplate()
{

}

void CDDDbTemplate::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbTemplate::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "TUV") {
            m_tuv = QSharedPointer<CDDDbTuv>::create();
            if (m_tuv) {
                m_tuv->load(childElement);
            }
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
