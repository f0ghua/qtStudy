#include "CDDDbSTATEGROUP.h"

#include "CDDDbSTATEGROUPS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATEGROUPS::CDDDbSTATEGROUPS()
{
}

CDDDbSTATEGROUPS::~CDDDbSTATEGROUPS()
{
}

void CDDDbSTATEGROUPS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "STATEGROUP") {
            m_stategroup = QSharedPointer<CDDDbSTATEGROUP>::create();
            if (m_stategroup) {
                m_stategroup->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
