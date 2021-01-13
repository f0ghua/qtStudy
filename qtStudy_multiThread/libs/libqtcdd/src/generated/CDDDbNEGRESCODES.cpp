#include "CDDDbNEGRESCODE.h"

#include "CDDDbNEGRESCODES.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODES::CDDDbNEGRESCODES()
{
}

CDDDbNEGRESCODES::~CDDDbNEGRESCODES()
{
}

void CDDDbNEGRESCODES::load(const QDomElement &element)
{
    m_bl = element.attribute("bl");
    m_bo = element.attribute("bo");
    m_stateGroupDefault = element.attribute("stateGroupDefault");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "NEGRESCODE") {
            auto o = QSharedPointer<CDDDbNEGRESCODE>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_negrescodes.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
