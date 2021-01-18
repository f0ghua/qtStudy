#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbCONSTCOMPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCONSTCOMPImpl::CDDDbCONSTCOMPImpl()
{
}

CDDDbCONSTCOMPImpl::~CDDDbCONSTCOMPImpl()
{
}

void CDDDbCONSTCOMPImpl::load(const QDomElement &element)
{
    m_bl = element.attribute("bl");
    m_id = element.attribute("id");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_respsupbit = element.attribute("respsupbit");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

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
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
