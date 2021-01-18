#include "CDDDbCSTRDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbDIDATTSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDATTSImpl::CDDDbDIDATTSImpl()
{
}

CDDDbDIDATTSImpl::~CDDDbDIDATTSImpl()
{
}

void CDDDbDIDATTSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CSTRDEF") {
                auto o = QSharedPointer<CDDDbCSTRDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elCstrdefs.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "UNSDEF") {
                auto o = QSharedPointer<CDDDbUNSDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elUnsdefs.insert(o->m_id, o);
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
