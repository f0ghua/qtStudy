#include "CDDDbIDENT.h"
#include "CDDDbLINCOMP.h"
#include "CDDDbMUXDT.h"
#include "CDDDbSTRUCTDT.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbDATATYPESImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDATATYPESImpl::CDDDbDATATYPESImpl()
{
}

CDDDbDATATYPESImpl::~CDDDbDATATYPESImpl()
{
}

void CDDDbDATATYPESImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "IDENT") {
                auto o = QSharedPointer<CDDDbIDENT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elIdents.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "LINCOMP") {
                auto o = QSharedPointer<CDDDbLINCOMP>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elLincomps.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "MUXDT") {
                auto o = QSharedPointer<CDDDbMUXDT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elMuxdts.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "STRUCTDT") {
                auto o = QSharedPointer<CDDDbSTRUCTDT>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elStructdts.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "TEXTTBL") {
                auto o = QSharedPointer<CDDDbTEXTTBL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elTexttbls.insert(o->m_id, o);
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
