#include "CDDDbENUMDEF.h"
#include "CDDDbSGNDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbSERVICEATTSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSERVICEATTSImpl::CDDDbSERVICEATTSImpl()
{
}

CDDDbSERVICEATTSImpl::~CDDDbSERVICEATTSImpl()
{
}

void CDDDbSERVICEATTSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ENUMDEF") {
                auto o = QSharedPointer<CDDDbENUMDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elEnumdefs.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "SGNDEF") {
                m_elSgndef = QSharedPointer<CDDDbSGNDEF>::create();
                if (m_elSgndef) {
                    m_elSgndef->load(childElement);
                }
            } else if (elementName == "STRDEF") {
                auto o = QSharedPointer<CDDDbSTRDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elStrdefs.insert(o->m_id, o);
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
