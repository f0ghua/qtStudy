#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDATAOBJImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDATAOBJImpl::CDDDbDATAOBJImpl()
{
}

CDDDbDATAOBJImpl::~CDDDbDATAOBJImpl()
{
}

void CDDDbDATAOBJImpl::load(const QDomElement &element)
{
    m_dataObjectRef = element.attribute("dataObjectRef");
    m_def = element.attribute("def");
    m_dtref = element.attribute("dtref");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "NAME") {
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
