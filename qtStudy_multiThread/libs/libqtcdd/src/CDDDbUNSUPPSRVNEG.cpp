#include "CDDDbCONSTCOMP.h"
#include "CDDDbCONTENTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMP.h"

#include "CDDDbUNSUPPSRVNEG.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNSUPPSRVNEG::CDDDbUNSUPPSRVNEG()
{
}

CDDDbUNSUPPSRVNEG::~CDDDbUNSUPPSRVNEG()
{
}

void CDDDbUNSUPPSRVNEG::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CONSTCOMP") {
            m_constcomp = QSharedPointer<CDDDbCONSTCOMP>::create();
            if (m_constcomp) {
                m_constcomp->load(childElement);
            }
        } else if (elementName == "CONTENTCOMP") {
            m_contentcomp = QSharedPointer<CDDDbCONTENTCOMP>::create();
            if (m_contentcomp) {
                m_contentcomp->load(childElement);
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
