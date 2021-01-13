#include "CDDDbTUV.h"

#include "CDDDbADDINFO.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbADDINFO::CDDDbADDINFO()
{
}

CDDDbADDINFO::~CDDDbADDINFO()
{
}

void CDDDbADDINFO::load(const QDomElement &element)
{

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
