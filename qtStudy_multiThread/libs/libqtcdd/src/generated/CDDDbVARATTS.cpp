#include "CDDDbENUMDEF.h"

#include "CDDDbVARATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbVARATTS::CDDDbVARATTS()
{
}

CDDDbVARATTS::~CDDDbVARATTS()
{
}

void CDDDbVARATTS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ENUMDEF") {
            m_enumdef = QSharedPointer<CDDDbENUMDEF>::create();
            if (m_enumdef) {
                m_enumdef->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
