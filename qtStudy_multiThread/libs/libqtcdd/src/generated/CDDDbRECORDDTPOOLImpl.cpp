#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDTPOOLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDDTPOOLImpl::CDDDbRECORDDTPOOLImpl()
{
}

CDDDbRECORDDTPOOLImpl::~CDDDbRECORDDTPOOLImpl()
{
}

void CDDDbRECORDDTPOOLImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "RECORDDT") {
                auto o = QSharedPointer<CDDDbRECORDDT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elRecorddts.insert(o->m_id, o);
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
