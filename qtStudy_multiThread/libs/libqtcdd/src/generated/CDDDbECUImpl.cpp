#include "CDDDbCSTR.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbFAULTMEMORY.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbUNS.h"
#include "CDDDbVAR.h"

#include "CDDDbECUImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECUImpl::CDDDbECUImpl()
{
}

CDDDbECUImpl::~CDDDbECUImpl()
{
}

void CDDDbECUImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_maxCombinedServiceIds = element.attribute("maxCombinedServiceIds");
    m_maxEcuSchedulerIds = element.attribute("maxEcuSchedulerIds");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CSTR") {
                auto o = QSharedPointer<CDDDbCSTR>::create();
                if (o) {
                    o->load(childElement);
                    m_elCstrs.append(o);
                }
            } else if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "ENUM") {
                auto o = QSharedPointer<CDDDbENUM>::create();
                if (o) {
                    o->load(childElement);
                    m_elEnums.append(o);
                }
            } else if (elementName == "FAULTMEMORY") {
                m_elFaultmemory = QSharedPointer<CDDDbFAULTMEMORY>::create();
                if (m_elFaultmemory) {
                    m_elFaultmemory->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "UNS") {
                auto o = QSharedPointer<CDDDbUNS>::create();
                if (o) {
                    o->load(childElement);
                    m_elUnss.append(o);
                }
            } else if (elementName == "VAR") {
                auto o = QSharedPointer<CDDDbVAR>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elVars.insert(o->m_id, o);
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
