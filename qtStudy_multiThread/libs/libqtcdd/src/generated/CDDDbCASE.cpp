#include "CDDDbSTRUCTURE.h"

#include "CDDDbCASE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCASE::CDDDbCASE()
{
}

CDDDbCASE::~CDDDbCASE()
{
}

void CDDDbCASE::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_oid = element.attribute("oid");
    m_s = element.attribute("s");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "STRUCTURE") {
            m_structure = QSharedPointer<CDDDbSTRUCTURE>::create();
            if (m_structure) {
                m_structure->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
