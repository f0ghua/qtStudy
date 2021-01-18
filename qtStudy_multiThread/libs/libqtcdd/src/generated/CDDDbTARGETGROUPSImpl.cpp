#include "CDDDbTARGETGROUP.h"

#include "CDDDbTARGETGROUPSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTARGETGROUPSImpl::CDDDbTARGETGROUPSImpl()
{
}

CDDDbTARGETGROUPSImpl::~CDDDbTARGETGROUPSImpl()
{
}

void CDDDbTARGETGROUPSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "TARGETGROUP") {
                auto o = QSharedPointer<CDDDbTARGETGROUP>::create();
                if (o) {
                    o->load(childElement);
                    m_elTargetgroups.append(o);
                }
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
