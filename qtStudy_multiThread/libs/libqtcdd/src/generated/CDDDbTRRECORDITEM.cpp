#include "CDDDbTEXT.h"

#include "CDDDbTRRECORDITEM.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTRRECORDITEM::CDDDbTRRECORDITEM()
{
}

CDDDbTRRECORDITEM::~CDDDbTRRECORDITEM()
{
}

void CDDDbTRRECORDITEM::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "TEXT") {
            m_text = QSharedPointer<CDDDbTEXT>::create();
            if (m_text) {
                m_text->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
