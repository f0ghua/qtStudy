#include "CDDDbDATAOBJ.h"

#include "CDDDbSTRUCTURE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRUCTURE::CDDDbSTRUCTURE()
{
}

CDDDbSTRUCTURE::~CDDDbSTRUCTURE()
{
}

void CDDDbSTRUCTURE::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DATAOBJ") {
            auto o = QSharedPointer<CDDDbDATAOBJ>::create();
            if (o) {
                o->load(childElement);
                m_dataobjs.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
