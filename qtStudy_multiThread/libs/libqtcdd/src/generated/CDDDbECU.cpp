#include "CDDDbCSTR.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbFAULTMEMORY.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbUNS.h"
#include "CDDDbVAR.h"

#include "CDDDbECU.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECU::CDDDbECU()
{
}

CDDDbECU::~CDDDbECU()
{
}

void CDDDbECU::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_maxCombinedServiceIds = element.attribute("maxCombinedServiceIds");
    m_maxEcuSchedulerIds = element.attribute("maxEcuSchedulerIds");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CSTR") {
            m_cstr = QSharedPointer<CDDDbCSTR>::create();
            if (m_cstr) {
                m_cstr->load(childElement);
            }
        } else if (elementName == "DESC") {
            m_desc = QSharedPointer<CDDDbDESC>::create();
            if (m_desc) {
                m_desc->load(childElement);
            }
        } else if (elementName == "ENUM") {
            m_enum = QSharedPointer<CDDDbENUM>::create();
            if (m_enum) {
                m_enum->load(childElement);
            }
        } else if (elementName == "FAULTMEMORY") {
            m_faultmemory = QSharedPointer<CDDDbFAULTMEMORY>::create();
            if (m_faultmemory) {
                m_faultmemory->load(childElement);
            }
        } else if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "UNS") {
            auto o = QSharedPointer<CDDDbUNS>::create();
            if (o) {
                o->load(childElement);
                m_unss.append(o);
            }
        } else if (elementName == "VAR") {
            auto o = QSharedPointer<CDDDbVAR>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_vars.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
