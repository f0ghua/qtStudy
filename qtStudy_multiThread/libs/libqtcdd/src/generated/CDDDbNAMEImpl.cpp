#include "CDDDbTUV.h"

#include "CDDDbNAMEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNAMEImpl::CDDDbNAMEImpl()
{
}

CDDDbNAMEImpl::~CDDDbNAMEImpl()
{
}

void CDDDbNAMEImpl::load(const QDomElement &element)
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
                    m_elTuvs.insert(o->m_lang, o);
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
