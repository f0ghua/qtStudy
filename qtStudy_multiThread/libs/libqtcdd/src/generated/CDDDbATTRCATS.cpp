#include "CDDDbATTRCAT.h"

#include "CDDDbATTRCATS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbATTRCATS::CDDDbATTRCATS()
{
}

CDDDbATTRCATS::~CDDDbATTRCATS()
{
}

void CDDDbATTRCATS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ATTRCAT") {
            auto o = QSharedPointer<CDDDbATTRCAT>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_attrcats.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
