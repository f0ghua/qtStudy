#include "CDDDbTUV.h"

#include "CDDDbSHORTCUTNAMEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTCUTNAMEImpl::CDDDbSHORTCUTNAMEImpl()
{
}

CDDDbSHORTCUTNAMEImpl::~CDDDbSHORTCUTNAMEImpl()
{
}

void CDDDbSHORTCUTNAMEImpl::load(const QDomElement &element)
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
