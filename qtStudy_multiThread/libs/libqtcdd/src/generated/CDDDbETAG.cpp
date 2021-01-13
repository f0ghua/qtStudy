#include "CDDDbTUV.h"

#include "CDDDbETAG.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbETAG::CDDDbETAG()
{
}

CDDDbETAG::~CDDDbETAG()
{
}

void CDDDbETAG::load(const QDomElement &element)
{
    m_v = element.attribute("v");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "TUV") {
            m_tuv = QSharedPointer<CDDDbTUV>::create();
            if (m_tuv) {
                m_tuv->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
