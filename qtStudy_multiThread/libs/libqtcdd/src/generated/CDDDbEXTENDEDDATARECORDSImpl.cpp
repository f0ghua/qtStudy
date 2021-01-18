#include "CDDDbEXTENDEDDATARECORD.h"

#include "CDDDbEXTENDEDDATARECORDSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEXTENDEDDATARECORDSImpl::CDDDbEXTENDEDDATARECORDSImpl()
{
}

CDDDbEXTENDEDDATARECORDSImpl::~CDDDbEXTENDEDDATARECORDSImpl()
{
}

void CDDDbEXTENDEDDATARECORDSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "EXTENDEDDATARECORD") {
                m_elExtendeddatarecord = QSharedPointer<CDDDbEXTENDEDDATARECORD>::create();
                if (m_elExtendeddatarecord) {
                    m_elExtendeddatarecord->load(childElement);
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
