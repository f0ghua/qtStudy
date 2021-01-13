#include "CDDDbIDENT.h"
#include "CDDDbLINCOMP.h"
#include "CDDDbMUXDT.h"
#include "CDDDbSTRUCTDT.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbDATATYPES.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDATATYPES::CDDDbDATATYPES()
{
}

CDDDbDATATYPES::~CDDDbDATATYPES()
{
}

void CDDDbDATATYPES::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "IDENT") {
            auto o = QSharedPointer<CDDDbIDENT>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_idents.insert(o->m_id, o);
                }
            }
        } else if (elementName == "LINCOMP") {
            auto o = QSharedPointer<CDDDbLINCOMP>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_lincomps.insert(o->m_id, o);
                }
            }
        } else if (elementName == "MUXDT") {
            m_muxdt = QSharedPointer<CDDDbMUXDT>::create();
            if (m_muxdt) {
                m_muxdt->load(childElement);
            }
        } else if (elementName == "STRUCTDT") {
            auto o = QSharedPointer<CDDDbSTRUCTDT>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_structdts.insert(o->m_id, o);
                }
            }
        } else if (elementName == "TEXTTBL") {
            auto o = QSharedPointer<CDDDbTEXTTBL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_texttbls.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
