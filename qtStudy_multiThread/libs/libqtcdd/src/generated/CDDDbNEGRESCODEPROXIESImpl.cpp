#include "CDDDbNEGRESCODEPROXY.h"

#include "CDDDbNEGRESCODEPROXIESImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODEPROXIESImpl::CDDDbNEGRESCODEPROXIESImpl()
{
}

CDDDbNEGRESCODEPROXIESImpl::~CDDDbNEGRESCODEPROXIESImpl()
{
}

void CDDDbNEGRESCODEPROXIESImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "NEGRESCODEPROXY") {
                auto o = QSharedPointer<CDDDbNEGRESCODEPROXY>::create();
                if (o) {
                    o->load(childElement);
                    m_elNegrescodeproxys.append(o);
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
