#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSPECIFICSNAPSHOTRECORD.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSPECIFICSNAPSHOTRECORD::CDDDbSPECIFICSNAPSHOTRECORD()
{
}

CDDDbSPECIFICSNAPSHOTRECORD::~CDDDbSPECIFICSNAPSHOTRECORD()
{
}

void CDDDbSPECIFICSNAPSHOTRECORD::load(const QDomElement &element)
{
    m_csdRef = element.attribute("csdRef");
    m_mayBeDel = element.attribute("mayBeDel");
    m_mayBeMod = element.attribute("mayBeMod");
    m_mayBeModData = element.attribute("mayBeModData");
    m_oid = element.attribute("oid");
    m_rn = element.attribute("rn");
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
