#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbDCLTMPLATTSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDCLTMPLATTSImpl::CDDDbDCLTMPLATTSImpl()
{
}

CDDDbDCLTMPLATTSImpl::~CDDDbDCLTMPLATTSImpl()
{
}

void CDDDbDCLTMPLATTSImpl::load(const QDomElement &element)
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
            } else if (elementName == "ENUMDEF") {
                auto o = QSharedPointer<CDDDbENUMDEF>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elEnumdefs.insert(o->m_id, o);
                    }
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
