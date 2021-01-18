#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDATAOBJImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDDATAOBJImpl::CDDDbRECORDDATAOBJImpl()
{
}

CDDDbRECORDDATAOBJImpl::~CDDDbRECORDDATAOBJImpl()
{
}

void CDDDbRECORDDATAOBJImpl::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_rtSpec = element.attribute("rtSpec");
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
            } else if (elementName == "RECORDDT") {
                auto o = QSharedPointer<CDDDbRECORDDT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elRecorddts.insert(o->m_id, o);
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
