#include "CDDDbCONSTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNEG.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEG::CDDDbNEG()
{
}

CDDDbNEG::~CDDDbNEG()
{
}

void CDDDbNEG::load(const QDomElement &element)
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
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
