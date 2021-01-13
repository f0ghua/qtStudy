#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDATAOBJ.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDDATAOBJ::CDDDbRECORDDATAOBJ()
{
}

CDDDbRECORDDATAOBJ::~CDDDbRECORDDATAOBJ()
{
}

void CDDDbRECORDDATAOBJ::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_rtSpec = element.attribute("rtSpec");
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
        } else if (elementName == "RECORDDT") {
            m_recorddt = QSharedPointer<CDDDbRECORDDT>::create();
            if (m_recorddt) {
                m_recorddt->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
