#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbNEGRESCODE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODE::CDDDbNEGRESCODE()
{
}

CDDDbNEGRESCODE::~CDDDbNEGRESCODE()
{
}

void CDDDbNEGRESCODE::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

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
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
