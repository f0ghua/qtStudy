#include "CDDDbCOMMONSTRING.h"

#include "CDDDbCSTRImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCSTRImpl::CDDDbCSTRImpl()
{
}

CDDDbCSTRImpl::~CDDDbCSTRImpl()
{
}

void CDDDbCSTRImpl::load(const QDomElement &element)
{
    m_attrref = element.attribute("attrref");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "COMMONSTRING") {
                m_elCommonstring = QSharedPointer<CDDDbCOMMONSTRING>::create();
                if (m_elCommonstring) {
                    m_elCommonstring->load(childElement);
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
