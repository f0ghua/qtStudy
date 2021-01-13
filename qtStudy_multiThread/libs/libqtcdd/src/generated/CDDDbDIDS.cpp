#include "CDDDbDID.h"

#include "CDDDbDIDS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDS::CDDDbDIDS()
{
}

CDDDbDIDS::~CDDDbDIDS()
{
}

void CDDDbDIDS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DID") {
            auto o = QSharedPointer<CDDDbDID>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_dids.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
