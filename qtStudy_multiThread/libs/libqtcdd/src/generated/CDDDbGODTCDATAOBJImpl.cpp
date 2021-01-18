#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbGODTCDATAOBJImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbGODTCDATAOBJImpl::CDDDbGODTCDATAOBJImpl()
{
}

CDDDbGODTCDATAOBJImpl::~CDDDbGODTCDATAOBJImpl()
{
}

void CDDDbGODTCDATAOBJImpl::load(const QDomElement &element)
{
    m_def = element.attribute("def");
    m_individualDtcs = element.attribute("individualDtcs");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
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
            } else if (elementName == "TEXTTBL") {
                auto o = QSharedPointer<CDDDbTEXTTBL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elTexttbls.insert(o->m_id, o);
                    }
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
