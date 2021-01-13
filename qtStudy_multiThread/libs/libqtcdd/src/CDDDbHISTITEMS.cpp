#include "CDDDbHISTITEM.h"

#include "CDDDbHISTITEMS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbHISTITEMS::CDDDbHISTITEMS()
{
}

CDDDbHISTITEMS::~CDDDbHISTITEMS()
{
}

void CDDDbHISTITEMS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "HISTITEM") {
            m_histitem = QSharedPointer<CDDDbHISTITEM>::create();
            if (m_histitem) {
                m_histitem->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
