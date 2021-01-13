#include "CDDDbCASE.h"
#include "CDDDbCVALUETYPE.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbMUXDT.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbMUXDT::CDDDbMUXDT()
{
}

CDDDbMUXDT::~CDDDbMUXDT()
{
}

void CDDDbMUXDT::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_dtref = element.attribute("dtref");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CASE") {
            auto o = QSharedPointer<CDDDbCASE>::create();
            if (o) {
                o->load(childElement);
                m_cases.append(o);
            }
        } else if (elementName == "CVALUETYPE") {
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
        } else if (elementName == "STRUCTURE") {
            m_structure = QSharedPointer<CDDDbSTRUCTURE>::create();
            if (m_structure) {
                m_structure->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
