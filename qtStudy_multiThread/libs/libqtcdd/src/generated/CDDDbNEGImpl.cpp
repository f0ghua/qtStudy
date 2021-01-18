#include "CDDDbCONSTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNEGImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGImpl::CDDDbNEGImpl()
{
}

CDDDbNEGImpl::~CDDDbNEGImpl()
{
}

void CDDDbNEGImpl::load(const QDomElement &element)
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
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
