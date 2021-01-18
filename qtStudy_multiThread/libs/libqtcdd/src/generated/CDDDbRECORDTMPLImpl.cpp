#include "CDDDbCVALUETYPE.h"
#include "CDDDbENUMRECORDITEMTMPL.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbTRRECORDITEMTMPL.h"
#include "CDDDbUNSRECORDITEMTMPL.h"

#include "CDDDbRECORDTMPLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDTMPLImpl::CDDDbRECORDTMPLImpl()
{
}

CDDDbRECORDTMPLImpl::~CDDDbRECORDTMPLImpl()
{
}

void CDDDbRECORDTMPLImpl::load(const QDomElement &element)
{
    m_spec = element.attribute("spec");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CVALUETYPE") {
                m_elCvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
                if (m_elCvaluetype) {
                    m_elCvaluetype->load(childElement);
                }
            } else if (elementName == "ENUMRECORDITEMTMPL") {
                auto o = QSharedPointer<CDDDbENUMRECORDITEMTMPL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elEnumrecorditemtmpls.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "PVALUETYPE") {
                m_elPvaluetype = QSharedPointer<CDDDbPVALUETYPE>::create();
                if (m_elPvaluetype) {
                    m_elPvaluetype->load(childElement);
                }
            } else if (elementName == "TRRECORDITEMTMPL") {
                auto o = QSharedPointer<CDDDbTRRECORDITEMTMPL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elTrrecorditemtmpls.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "UNSRECORDITEMTMPL") {
                auto o = QSharedPointer<CDDDbUNSRECORDITEMTMPL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elUnsrecorditemtmpls.insert(o->m_id, o);
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
