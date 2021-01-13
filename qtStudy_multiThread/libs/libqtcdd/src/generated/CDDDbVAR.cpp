#include "CDDDbDIAGCLASS.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbDIDREFS.h"
#include "CDDDbJOBCNR.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbVAR.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbVAR::CDDDbVAR()
{
}

CDDDbVAR::~CDDDbVAR()
{
}

void CDDDbVAR::load(const QDomElement &element)
{
    m_base = element.attribute("base");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DIAGCLASS") {
            auto o = QSharedPointer<CDDDbDIAGCLASS>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_diagclasss.insert(o->m_id, o);
                }
            }
        } else if (elementName == "DIAGINST") {
            auto o = QSharedPointer<CDDDbDIAGINST>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_diaginsts.insert(o->m_id, o);
                }
            }
        } else if (elementName == "DIDREFS") {
            m_didrefs = QSharedPointer<CDDDbDIDREFS>::create();
            if (m_didrefs) {
                m_didrefs->load(childElement);
            }
        } else if (elementName == "JOBCNR") {
            m_jobcnr = QSharedPointer<CDDDbJOBCNR>::create();
            if (m_jobcnr) {
                m_jobcnr->load(childElement);
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
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
