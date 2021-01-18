#include "CDDDbPROTOCOLSERVICE.h"

#include "CDDDbPROTOCOLSERVICESImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICESImpl::CDDDbPROTOCOLSERVICESImpl()
{
}

CDDDbPROTOCOLSERVICESImpl::~CDDDbPROTOCOLSERVICESImpl()
{
}

void CDDDbPROTOCOLSERVICESImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "PROTOCOLSERVICE") {
                auto o = QSharedPointer<CDDDbPROTOCOLSERVICE>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elProtocolservices.insert(o->m_id, o);
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
