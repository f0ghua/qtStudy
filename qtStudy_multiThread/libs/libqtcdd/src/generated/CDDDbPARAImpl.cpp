#include "CDDDbFC.h"

#include "CDDDbPARAImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPARAImpl::CDDDbPARAImpl()
{
}

CDDDbPARAImpl::~CDDDbPARAImpl()
{
}

void CDDDbPARAImpl::load(const QDomElement &element)
{
    m_list = element.attribute("list");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "FC") {
                auto o = QSharedPointer<CDDDbFC>::create();
                if (o) {
                    o->load(childElement);
                    m_elFcs.append(o);
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
