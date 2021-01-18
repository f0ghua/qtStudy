#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMP.h"

#include "CDDDbUNSUPPSRVNEGImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNSUPPSRVNEGImpl::CDDDbUNSUPPSRVNEGImpl()
{
}

CDDDbUNSUPPSRVNEGImpl::~CDDDbUNSUPPSRVNEGImpl()
{
}

void CDDDbUNSUPPSRVNEGImpl::load(const QDomElement &element)
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
            } else if (elementName == "STATICCOMP") {
                m_elStaticcomp = QSharedPointer<CDDDbSTATICCOMP>::create();
                if (m_elStaticcomp) {
                    m_elStaticcomp->load(childElement);
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
