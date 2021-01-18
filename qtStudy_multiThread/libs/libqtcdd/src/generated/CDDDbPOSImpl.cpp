#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbEOSITERCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbNUMITERCOMP.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATICCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbPOSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPOSImpl::CDDDbPOSImpl()
{
}

CDDDbPOSImpl::~CDDDbPOSImpl()
{
}

void CDDDbPOSImpl::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CONSTCOMP") {
                auto o = QSharedPointer<CDDDbCONSTCOMP>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elConstcomps.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "CONTENTCOMP") {
                auto o = QSharedPointer<CDDDbCONTENTCOMP>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elContentcomps.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "EOSITERCOMP") {
                m_elEositercomp = QSharedPointer<CDDDbEOSITERCOMP>::create();
                if (m_elEositercomp) {
                    m_elEositercomp->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "NUMITERCOMP") {
                m_elNumitercomp = QSharedPointer<CDDDbNUMITERCOMP>::create();
                if (m_elNumitercomp) {
                    m_elNumitercomp->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "SIMPLEPROXYCOMP") {
                auto o = QSharedPointer<CDDDbSIMPLEPROXYCOMP>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elSimpleproxycomps.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "STATICCOMP") {
                m_elStaticcomp = QSharedPointer<CDDDbSTATICCOMP>::create();
                if (m_elStaticcomp) {
                    m_elStaticcomp->load(childElement);
                }
            } else if (elementName == "STATUSDTCPROXYCOMP") {
                m_elStatusdtcproxycomp = QSharedPointer<CDDDbSTATUSDTCPROXYCOMP>::create();
                if (m_elStatusdtcproxycomp) {
                    m_elStatusdtcproxycomp->load(childElement);
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
