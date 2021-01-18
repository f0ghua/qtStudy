#include "CDDDbSTATEGROUP.h"

#include "CDDDbSTATEGROUPSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATEGROUPSImpl::CDDDbSTATEGROUPSImpl()
{
}

CDDDbSTATEGROUPSImpl::~CDDDbSTATEGROUPSImpl()
{
}

void CDDDbSTATEGROUPSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "STATEGROUP") {
                auto o = QSharedPointer<CDDDbSTATEGROUP>::create();
                if (o) {
                    o->load(childElement);
                    m_elStategroups.append(o);
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
