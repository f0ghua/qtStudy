#include "CDDDbENUMDEF.h"

#include "CDDDbDIAGCLASSATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGCLASSATTS::CDDDbDIAGCLASSATTS()
{
}

CDDDbDIAGCLASSATTS::~CDDDbDIAGCLASSATTS()
{
}

void CDDDbDIAGCLASSATTS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ENUMDEF") {
            auto o = QSharedPointer<CDDDbENUMDEF>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_enumdefs.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
