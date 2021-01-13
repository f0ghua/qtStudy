#include "CDDDbLABEL.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDOCTMPL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDOCTMPL::CDDDbDOCTMPL()
{
}

CDDDbDOCTMPL::~CDDDbDOCTMPL()
{
}

void CDDDbDOCTMPL::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_saveno = element.attribute("saveno");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "LABEL") {
            m_label = QSharedPointer<CDDDbLABEL>::create();
            if (m_label) {
                m_label->load(childElement);
            }
        } else if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
