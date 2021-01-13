#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIDDATAREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDDATAREF::CDDDbDIDDATAREF()
{
}

CDDDbDIDDATAREF::~CDDDbDIDDATAREF()
{
}

void CDDDbDIDDATAREF::load(const QDomElement &element)
{
    m_didRef = element.attribute("didRef");
    m_oid = element.attribute("oid");

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
