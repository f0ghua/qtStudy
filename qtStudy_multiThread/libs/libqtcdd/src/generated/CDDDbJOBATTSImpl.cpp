#include "CDDDbENUMDEF.h"

#include "CDDDbJOBATTSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbJOBATTSImpl::CDDDbJOBATTSImpl()
{
}

CDDDbJOBATTSImpl::~CDDDbJOBATTSImpl()
{
}

void CDDDbJOBATTSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ENUMDEF") {
                auto o = QSharedPointer<CDDDbENUMDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elEnumdefs.insert(o->m_id, o);
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
