#include "CDDDbAUTHOR.h"

#include "CDDDbAUTHORSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAUTHORSImpl::CDDDbAUTHORSImpl()
{
}

CDDDbAUTHORSImpl::~CDDDbAUTHORSImpl()
{
}

void CDDDbAUTHORSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "AUTHOR") {
                m_elAuthor = QSharedPointer<CDDDbAUTHOR>::create();
                if (m_elAuthor) {
                    m_elAuthor->load(childElement);
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
