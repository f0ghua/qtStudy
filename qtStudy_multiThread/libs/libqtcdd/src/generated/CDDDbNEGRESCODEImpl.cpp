#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbNEGRESCODEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODEImpl::CDDDbNEGRESCODEImpl()
{
}

CDDDbNEGRESCODEImpl::~CDDDbNEGRESCODEImpl()
{
}

void CDDDbNEGRESCODEImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
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
