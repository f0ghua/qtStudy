#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbEXTENDEDDATARECORD.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEXTENDEDDATARECORD::CDDDbEXTENDEDDATARECORD()
{
}

CDDDbEXTENDEDDATARECORD::~CDDDbEXTENDEDDATARECORD()
{
}

void CDDDbEXTENDEDDATARECORD::load(const QDomElement &element)
{
    m_mayBeDel = element.attribute("mayBeDel");
    m_mayBeMod = element.attribute("mayBeMod");
    m_mayBeModData = element.attribute("mayBeModData");
    m_oid = element.attribute("oid");
    m_rn = element.attribute("rn");
    m_supportEdrForDtc = element.attribute("supportEdrForDtc");
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
        } else if (elementName == "STRUCTURE") {
            m_structure = QSharedPointer<CDDDbSTRUCTURE>::create();
            if (m_structure) {
                m_structure->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
