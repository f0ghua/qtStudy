#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNUMITERCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNUMITERCOMP::CDDDbNUMITERCOMP()
{
}

CDDDbNUMITERCOMP::~CDDDbNUMITERCOMP()
{
}

void CDDDbNUMITERCOMP::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_selbm = element.attribute("selbm");
    m_selref = element.attribute("selref");
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
        } else if (elementName == "SIMPLEPROXYCOMP") {
            m_simpleproxycomp = QSharedPointer<CDDDbSIMPLEPROXYCOMP>::create();
            if (m_simpleproxycomp) {
                m_simpleproxycomp->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
