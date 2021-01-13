#include "CDDDbDIDREF.h"

#include "CDDDbDIDREFS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDREFS::CDDDbDIDREFS()
{
}

CDDDbDIDREFS::~CDDDbDIDREFS()
{
}

void CDDDbDIDREFS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DIDREF") {
            auto o = QSharedPointer<CDDDbDIDREF>::create();
            if (o) {
                o->load(childElement);
                m_didrefs.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
