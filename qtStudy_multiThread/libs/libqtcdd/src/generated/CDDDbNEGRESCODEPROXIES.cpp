#include "CDDDbNEGRESCODEPROXY.h"

#include "CDDDbNEGRESCODEPROXIES.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODEPROXIES::CDDDbNEGRESCODEPROXIES()
{
}

CDDDbNEGRESCODEPROXIES::~CDDDbNEGRESCODEPROXIES()
{
}

void CDDDbNEGRESCODEPROXIES::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "NEGRESCODEPROXY") {
            auto o = QSharedPointer<CDDDbNEGRESCODEPROXY>::create();
            if (o) {
                o->load(childElement);
                m_negrescodeproxys.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
