#include "CDDDbCVALUETYPE.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbTEXTMAP.h"

#include "CDDDbTEXTTBL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTEXTTBL::CDDDbTEXTTBL()
{
}

CDDDbTEXTTBL::~CDDDbTEXTTBL()
{
}

void CDDDbTEXTTBL::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_xauth = element.attribute("xauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CVALUETYPE") {
            m_cvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
            if (m_cvaluetype) {
                m_cvaluetype->load(childElement);
            }
        } else if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "PVALUETYPE") {
            m_pvaluetype = QSharedPointer<CDDDbPVALUETYPE>::create();
            if (m_pvaluetype) {
                m_pvaluetype->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "TEXTMAP") {
            auto o = QSharedPointer<CDDDbTEXTMAP>::create();
            if (o) {
                o->load(childElement);
                m_textmaps.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
