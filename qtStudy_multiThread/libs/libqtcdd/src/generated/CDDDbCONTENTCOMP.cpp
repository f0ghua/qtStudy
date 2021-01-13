#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLECOMPCONT.h"

#include "CDDDbCONTENTCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCONTENTCOMP::CDDDbCONTENTCOMP()
{
}

CDDDbCONTENTCOMP::~CDDDbCONTENTCOMP()
{
}

void CDDDbCONTENTCOMP::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

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
        } else if (elementName == "SIMPLECOMPCONT") {
            m_simplecompcont = QSharedPointer<CDDDbSIMPLECOMPCONT>::create();
            if (m_simplecompcont) {
                m_simplecompcont->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
