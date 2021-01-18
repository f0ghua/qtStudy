#include "CDDDbCASE.h"
#include "CDDDbCVALUETYPE.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCTURE.h"

#include "CDDDbMUXDTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbMUXDTImpl::CDDDbMUXDTImpl()
{
}

CDDDbMUXDTImpl::~CDDDbMUXDTImpl()
{
}

void CDDDbMUXDTImpl::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_dtref = element.attribute("dtref");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CASE") {
                auto o = QSharedPointer<CDDDbCASE>::create();
                if (o) {
                    o->load(childElement);
                    m_elCases.append(o);
                }
            } else if (elementName == "CVALUETYPE") {
                m_elCvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
                if (m_elCvaluetype) {
                    m_elCvaluetype->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "PVALUETYPE") {
                m_elPvaluetype = QSharedPointer<CDDDbPVALUETYPE>::create();
                if (m_elPvaluetype) {
                    m_elPvaluetype->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "STRUCTURE") {
                m_elStructure = QSharedPointer<CDDDbSTRUCTURE>::create();
                if (m_elStructure) {
                    m_elStructure->load(childElement);
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
