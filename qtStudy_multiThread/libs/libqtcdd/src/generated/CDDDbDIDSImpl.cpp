#include "CDDDbDID.h"

#include "CDDDbDIDSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDSImpl::CDDDbDIDSImpl()
{
}

CDDDbDIDSImpl::~CDDDbDIDSImpl()
{
}

void CDDDbDIDSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DID") {
                auto o = QSharedPointer<CDDDbDID>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDids.insert(o->m_id, o);
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
