#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbJOBCNR.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbJOBCNR::CDDDbJOBCNR()
{
}

CDDDbJOBCNR::~CDDDbJOBCNR()
{
}

void CDDDbJOBCNR::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_req = element.attribute("req");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");

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
