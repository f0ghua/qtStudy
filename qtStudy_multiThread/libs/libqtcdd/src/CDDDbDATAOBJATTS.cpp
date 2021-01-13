#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbDATAOBJATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDATAOBJATTS::CDDDbDATAOBJATTS()
{
}

CDDDbDATAOBJATTS::~CDDDbDATAOBJATTS()
{
}

void CDDDbDATAOBJATTS::load(const QDomElement &element)
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
            m_enumdef = QSharedPointer<CDDDbENUMDEF>::create();
            if (m_enumdef) {
                m_enumdef->load(childElement);
            }
        } else if (elementName == "STRDEF") {
            m_strdef = QSharedPointer<CDDDbSTRDEF>::create();
            if (m_strdef) {
                m_strdef->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
