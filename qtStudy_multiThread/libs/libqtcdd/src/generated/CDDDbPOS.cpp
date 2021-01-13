#include "CDDDbCONSTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATICCOMP.h"

#include "CDDDbPOS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPOS::CDDDbPOS()
{
}

CDDDbPOS::~CDDDbPOS()
{
}

void CDDDbPOS::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CONSTCOMP") {
            auto o = QSharedPointer<CDDDbCONSTCOMP>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_constcomps.insert(o->m_id, o);
                }
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
        } else if (elementName == "SIMPLEPROXYCOMP") {
            m_simpleproxycomp = QSharedPointer<CDDDbSIMPLEPROXYCOMP>::create();
            if (m_simpleproxycomp) {
                m_simpleproxycomp->load(childElement);
            }
        } else if (elementName == "STATICCOMP") {
            m_staticcomp = QSharedPointer<CDDDbSTATICCOMP>::create();
            if (m_staticcomp) {
                m_staticcomp->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
