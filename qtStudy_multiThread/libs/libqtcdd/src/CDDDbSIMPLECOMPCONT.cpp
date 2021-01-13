#include "CDDDbSPECDATAOBJ.h"

#include "CDDDbSIMPLECOMPCONT.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSIMPLECOMPCONT::CDDDbSIMPLECOMPCONT()
{
}

CDDDbSIMPLECOMPCONT::~CDDDbSIMPLECOMPCONT()
{
}

void CDDDbSIMPLECOMPCONT::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "SPECDATAOBJ") {
            m_specdataobj = QSharedPointer<CDDDbSPECDATAOBJ>::create();
            if (m_specdataobj) {
                m_specdataobj->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
