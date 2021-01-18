#include "CDDDbNEGRESCODE.h"

#include "CDDDbNEGRESCODESImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODESImpl::CDDDbNEGRESCODESImpl()
{
}

CDDDbNEGRESCODESImpl::~CDDDbNEGRESCODESImpl()
{
}

void CDDDbNEGRESCODESImpl::load(const QDomElement &element)
{
    m_bl = element.attribute("bl");
    m_bo = element.attribute("bo");
    m_stateGroupDefault = element.attribute("stateGroupDefault");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "NEGRESCODE") {
                auto o = QSharedPointer<CDDDbNEGRESCODE>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elNegrescodes.insert(o->m_id, o);
                    }
                }
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
