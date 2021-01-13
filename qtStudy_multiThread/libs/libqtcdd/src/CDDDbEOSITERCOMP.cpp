#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbEOSITERCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEOSITERCOMP::CDDDbEOSITERCOMP()
{
}

CDDDbEOSITERCOMP::~CDDDbEOSITERCOMP()
{
}

void CDDDbEOSITERCOMP::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_minNumOfItems = element.attribute("minNumOfItems");
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
        } else if (elementName == "SIMPLEPROXYCOMP") {
            auto o = QSharedPointer<CDDDbSIMPLEPROXYCOMP>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_simpleproxycomps.insert(o->m_id, o);
                }
            }
        } else if (elementName == "STATUSDTCPROXYCOMP") {
            m_statusdtcproxycomp = QSharedPointer<CDDDbSTATUSDTCPROXYCOMP>::create();
            if (m_statusdtcproxycomp) {
                m_statusdtcproxycomp->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
