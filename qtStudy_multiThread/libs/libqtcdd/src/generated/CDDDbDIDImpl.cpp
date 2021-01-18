#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbDIDImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDImpl::CDDDbDIDImpl()
{
}

CDDDbDIDImpl::~CDDDbDIDImpl()
{
}

void CDDDbDIDImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_n = element.attribute("n");
    m_oid = element.attribute("oid");

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
            } else if (elementName == "STRUCTURE") {
                m_elStructure = QSharedPointer<CDDDbSTRUCTURE>::create();
                if (m_elStructure) {
                    m_elStructure->load(childElement);
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
