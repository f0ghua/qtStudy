#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbDID.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDID::CDDDbDID()
{
}

CDDDbDID::~CDDDbDID()
{
}

void CDDDbDID::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_n = element.attribute("n");
    m_oid = element.attribute("oid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "STRUCTURE") {
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
