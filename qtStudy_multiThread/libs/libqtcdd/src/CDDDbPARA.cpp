#include "CDDDbFC.h"

#include "CDDDbPARA.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPARA::CDDDbPARA()
{
}

CDDDbPARA::~CDDDbPARA()
{
}

void CDDDbPARA::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "FC") {
            m_fc = QSharedPointer<CDDDbFC>::create();
            if (m_fc) {
                m_fc->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
