#include "CDDDbPARA.h"

#include "CDDDbTUV.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTUV::CDDDbTUV()
{
}

CDDDbTUV::~CDDDbTUV()
{
}

void CDDDbTUV::load(const QDomElement &element)
{
    m_struct = element.attribute("struct");
    m_lang = element.attribute("xml:lang");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "PARA") {
            auto o = QSharedPointer<CDDDbPARA>::create();
            if (o) {
                o->load(childElement);
                m_paras.append(o);
            }
        }
        child = child.nextSibling();
    }
    m_text = element.text();
}

} // namespace cdd
} // namespace vector
