#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbGODTCDATAOBJ.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbGODTCDATAOBJ::CDDDbGODTCDATAOBJ()
{
}

CDDDbGODTCDATAOBJ::~CDDDbGODTCDATAOBJ()
{
}

void CDDDbGODTCDATAOBJ::load(const QDomElement &element)
{
    m_def = element.attribute("def");
    m_individualDtcs = element.attribute("individualDtcs");
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
        } else if (elementName == "TEXTTBL") {
            m_texttbl = QSharedPointer<CDDDbTEXTTBL>::create();
            if (m_texttbl) {
                m_texttbl->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
