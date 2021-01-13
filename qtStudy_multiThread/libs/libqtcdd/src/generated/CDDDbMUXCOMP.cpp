#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbMUXCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbMUXCOMP::CDDDbMUXCOMP()
{
}

CDDDbMUXCOMP::~CDDDbMUXCOMP()
{
}

void CDDDbMUXCOMP::load(const QDomElement &element)
{
    m_dest = element.attribute("dest");
    m_id = element.attribute("id");
    m_minbl = element.attribute("minbl");
    m_must = element.attribute("must");
    m_oid = element.attribute("oid");
    m_selbm = element.attribute("selbm");
    m_selref = element.attribute("selref");
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
