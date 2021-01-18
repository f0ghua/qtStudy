#include "CDDDbLABEL.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDOCTMPLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDOCTMPLImpl::CDDDbDOCTMPLImpl()
{
}

CDDDbDOCTMPLImpl::~CDDDbDOCTMPLImpl()
{
}

void CDDDbDOCTMPLImpl::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_saveno = element.attribute("saveno");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "LABEL") {
                m_elLabel = QSharedPointer<CDDDbLABEL>::create();
                if (m_elLabel) {
                    m_elLabel->load(childElement);
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
