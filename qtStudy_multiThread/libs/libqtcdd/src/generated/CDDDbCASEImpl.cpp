#include "CDDDbSTRUCTURE.h"

#include "CDDDbCASEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCASEImpl::CDDDbCASEImpl()
{
}

CDDDbCASEImpl::~CDDDbCASEImpl()
{
}

void CDDDbCASEImpl::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_oid = element.attribute("oid");
    m_s = element.attribute("s");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "STRUCTURE") {
                m_elStructure = QSharedPointer<CDDDbSTRUCTURE>::create();
                if (m_elStructure) {
                    m_elStructure->load(childElement);
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
