#include "CDDDbENUMDEF.h"
#include "CDDDbSGNDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbSERVICEATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSERVICEATTS::CDDDbSERVICEATTS()
{
}

CDDDbSERVICEATTS::~CDDDbSERVICEATTS()
{
}

void CDDDbSERVICEATTS::load(const QDomElement &element)
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
        } else if (elementName == "SGNDEF") {
            m_sgndef = QSharedPointer<CDDDbSGNDEF>::create();
            if (m_sgndef) {
                m_sgndef->load(childElement);
            }
        } else if (elementName == "STRDEF") {
            auto o = QSharedPointer<CDDDbSTRDEF>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_strdefs.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
