#include "CDDDbTEXT.h"

#include "CDDDbTEXTMAP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTEXTMAP::CDDDbTEXTMAP()
{
}

CDDDbTEXTMAP::~CDDDbTEXTMAP()
{
}

void CDDDbTEXTMAP::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_s = element.attribute("s");

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
