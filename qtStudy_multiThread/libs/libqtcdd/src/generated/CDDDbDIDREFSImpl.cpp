#include "CDDDbDIDREF.h"

#include "CDDDbDIDREFSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDREFSImpl::CDDDbDIDREFSImpl()
{
}

CDDDbDIDREFSImpl::~CDDDbDIDREFSImpl()
{
}

void CDDDbDIDREFSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DIDREF") {
                auto o = QSharedPointer<CDDDbDIDREF>::create();
                if (o) {
                    o->load(childElement);
                    m_elDidrefs.append(o);
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
