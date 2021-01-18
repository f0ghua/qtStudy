#include "CDDDbTEXT.h"

#include "CDDDbEXCLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEXCLImpl::CDDDbEXCLImpl()
{
}

CDDDbEXCLImpl::~CDDDbEXCLImpl()
{
}

void CDDDbEXCLImpl::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_inv = element.attribute("inv");
    m_s = element.attribute("s");

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
