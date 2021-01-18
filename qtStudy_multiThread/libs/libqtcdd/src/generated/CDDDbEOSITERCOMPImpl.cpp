#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbDOMAINDATAPROXYCOMP.h"
#include "CDDDbMUXCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"
#include "CDDDbSTATUSDTCPROXYCOMP.h"

#include "CDDDbEOSITERCOMPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEOSITERCOMPImpl::CDDDbEOSITERCOMPImpl()
{
}

CDDDbEOSITERCOMPImpl::~CDDDbEOSITERCOMPImpl()
{
}

void CDDDbEOSITERCOMPImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_maxNumOfItems = element.attribute("maxNumOfItems");
    m_minNumOfItems = element.attribute("minNumOfItems");
    m_must = element.attribute("must");
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
            } else if (elementName == "DOMAINDATAPROXYCOMP") {
                auto o = QSharedPointer<CDDDbDOMAINDATAPROXYCOMP>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDomaindataproxycomps.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "MUXCOMP") {
                m_elMuxcomp = QSharedPointer<CDDDbMUXCOMP>::create();
                if (m_elMuxcomp) {
                    m_elMuxcomp->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
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
