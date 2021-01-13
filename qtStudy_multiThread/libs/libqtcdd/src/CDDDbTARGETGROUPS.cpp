#include "CDDDbTARGETGROUP.h"

#include "CDDDbTARGETGROUPS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTARGETGROUPS::CDDDbTARGETGROUPS()
{
}

CDDDbTARGETGROUPS::~CDDDbTARGETGROUPS()
{
}

void CDDDbTARGETGROUPS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "TARGETGROUP") {
            auto o = QSharedPointer<CDDDbTARGETGROUP>::create();
            if (o) {
                o->load(childElement);
                m_targetgroups.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
