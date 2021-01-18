#include "CDDDbTEXT.h"

#include "CDDDbTRRECORDITEMImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTRRECORDITEMImpl::CDDDbTRRECORDITEMImpl()
{
}

CDDDbTRRECORDITEMImpl::~CDDDbTRRECORDITEMImpl()
{
}

void CDDDbTRRECORDITEMImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "TEXT") {
                m_elText = QSharedPointer<CDDDbTEXT>::create();
                if (m_elText) {
                    m_elText->load(childElement);
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
