#include "CDDDbCOMMONSTRING.h"

#include "CDDDbCSTR.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCSTR::CDDDbCSTR()
{
}

CDDDbCSTR::~CDDDbCSTR()
{
}

void CDDDbCSTR::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "COMMONSTRING") {
            m_commonstring = QSharedPointer<CDDDbCOMMONSTRING>::create();
            if (m_commonstring) {
                m_commonstring->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
