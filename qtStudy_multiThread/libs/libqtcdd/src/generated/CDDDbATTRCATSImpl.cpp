#include "CDDDbATTRCAT.h"

#include "CDDDbATTRCATSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbATTRCATSImpl::CDDDbATTRCATSImpl()
{
}

CDDDbATTRCATSImpl::~CDDDbATTRCATSImpl()
{
}

void CDDDbATTRCATSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ATTRCAT") {
                auto o = QSharedPointer<CDDDbATTRCAT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elAttrcats.insert(o->m_id, o);
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
