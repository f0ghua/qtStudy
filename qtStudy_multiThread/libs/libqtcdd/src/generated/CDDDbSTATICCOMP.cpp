#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTATICCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATICCOMP::CDDDbSTATICCOMP()
{
}

CDDDbSTATICCOMP::~CDDDbSTATICCOMP()
{
}

void CDDDbSTATICCOMP::load(const QDomElement &element)
{
    m_dtref = element.attribute("dtref");
    m_id = element.attribute("id");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");

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
