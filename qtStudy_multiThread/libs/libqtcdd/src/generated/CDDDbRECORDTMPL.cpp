#include "CDDDbCVALUETYPE.h"
#include "CDDDbENUMRECORDITEMTMPL.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbTRRECORDITEMTMPL.h"
#include "CDDDbUNSRECORDITEMTMPL.h"

#include "CDDDbRECORDTMPL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDTMPL::CDDDbRECORDTMPL()
{
}

CDDDbRECORDTMPL::~CDDDbRECORDTMPL()
{
}

void CDDDbRECORDTMPL::load(const QDomElement &element)
{
    m_spec = element.attribute("spec");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CVALUETYPE") {
            m_cvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
            if (m_cvaluetype) {
                m_cvaluetype->load(childElement);
            }
        } else if (elementName == "ENUMRECORDITEMTMPL") {
            auto o = QSharedPointer<CDDDbENUMRECORDITEMTMPL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_enumrecorditemtmpls.insert(o->m_id, o);
                }
            }
        } else if (elementName == "PVALUETYPE") {
            m_pvaluetype = QSharedPointer<CDDDbPVALUETYPE>::create();
            if (m_pvaluetype) {
                m_pvaluetype->load(childElement);
            }
        } else if (elementName == "TRRECORDITEMTMPL") {
            auto o = QSharedPointer<CDDDbTRRECORDITEMTMPL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_trrecorditemtmpls.insert(o->m_id, o);
                }
            }
        } else if (elementName == "UNSRECORDITEMTMPL") {
            auto o = QSharedPointer<CDDDbUNSRECORDITEMTMPL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_unsrecorditemtmpls.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
