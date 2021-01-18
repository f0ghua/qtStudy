#include "CDDDbRECORDTMPL.h"

#include "CDDDbRECORDTMPLSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDTMPLSImpl::CDDDbRECORDTMPLSImpl()
{
}

CDDDbRECORDTMPLSImpl::~CDDDbRECORDTMPLSImpl()
{
}

void CDDDbRECORDTMPLSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "RECORDTMPL") {
                auto o = QSharedPointer<CDDDbRECORDTMPL>::create();
                if (o) {
                    o->load(childElement);
                    m_elRecordtmpls.append(o);
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
