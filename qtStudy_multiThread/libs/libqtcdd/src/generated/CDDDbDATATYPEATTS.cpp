#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"

#include "CDDDbDATATYPEATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDATATYPEATTS::CDDDbDATATYPEATTS()
{
}

CDDDbDATATYPEATTS::~CDDDbDATATYPEATTS()
{
}

void CDDDbDATATYPEATTS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CSTRDEF") {
            auto o = QSharedPointer<CDDDbCSTRDEF>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_cstrdefs.insert(o->m_id, o);
                }
            }
        } else if (elementName == "ENUMDEF") {
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
