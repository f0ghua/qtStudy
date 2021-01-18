#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNUMITERCOMPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNUMITERCOMPImpl::CDDDbNUMITERCOMPImpl()
{
}

CDDDbNUMITERCOMPImpl::~CDDDbNUMITERCOMPImpl()
{
}

void CDDDbNUMITERCOMPImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_selbm = element.attribute("selbm");
    m_selref = element.attribute("selref");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "NAME") {
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
