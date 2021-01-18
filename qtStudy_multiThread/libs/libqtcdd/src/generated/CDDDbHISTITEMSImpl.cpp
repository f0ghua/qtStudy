#include "CDDDbHISTITEM.h"

#include "CDDDbHISTITEMSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbHISTITEMSImpl::CDDDbHISTITEMSImpl()
{
}

CDDDbHISTITEMSImpl::~CDDDbHISTITEMSImpl()
{
}

void CDDDbHISTITEMSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "HISTITEM") {
                auto o = QSharedPointer<CDDDbHISTITEM>::create();
                if (o) {
                    o->load(childElement);
                    m_elHistitems.append(o);
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
