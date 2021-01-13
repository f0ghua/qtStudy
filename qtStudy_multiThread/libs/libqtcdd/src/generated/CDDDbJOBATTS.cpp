#include "CDDDbENUMDEF.h"

#include "CDDDbJOBATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbJOBATTS::CDDDbJOBATTS()
{
}

CDDDbJOBATTS::~CDDDbJOBATTS()
{
}

void CDDDbJOBATTS::load(const QDomElement &element)
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
