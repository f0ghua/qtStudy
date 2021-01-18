#include "CDDDbPARA.h"

#include "CDDDbTUVImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTUVImpl::CDDDbTUVImpl()
{
}

CDDDbTUVImpl::~CDDDbTUVImpl()
{
}

void CDDDbTUVImpl::load(const QDomElement &element)
{
    m_struct = element.attribute("struct");
    m_lang = element.attribute("xml:lang");

    m_text = element.text();
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "PARA") {
                auto o = QSharedPointer<CDDDbPARA>::create();
                if (o) {
                    o->load(childElement);
                    m_elParas.append(o);
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
