#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSPECIFICSNAPSHOTRECORDImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSPECIFICSNAPSHOTRECORDImpl::CDDDbSPECIFICSNAPSHOTRECORDImpl()
{
}

CDDDbSPECIFICSNAPSHOTRECORDImpl::~CDDDbSPECIFICSNAPSHOTRECORDImpl()
{
}

void CDDDbSPECIFICSNAPSHOTRECORDImpl::load(const QDomElement &element)
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
