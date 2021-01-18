#include "CDDDbTUV.h"

#include "CDDDbDEFAULTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDEFAULTImpl::CDDDbDEFAULTImpl()
{
}

CDDDbDEFAULTImpl::~CDDDbDEFAULTImpl()
{
}

void CDDDbDEFAULTImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "TUV") {
                auto o = QSharedPointer<CDDDbTUV>::create();
                if (o) {
                    o->load(childElement);
                    m_elTuvs.append(o);
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
