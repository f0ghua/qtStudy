#include "CDDDbDIAGCLASS.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbDIAGINSTREF.h"
#include "CDDDbDIDREFS.h"
#include "CDDDbJOBCNR.h"
#include "CDDDbJOBCNRREF.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbVARImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbVARImpl::CDDDbVARImpl()
{
}

CDDDbVARImpl::~CDDDbVARImpl()
{
}

void CDDDbVARImpl::load(const QDomElement &element)
{
    m_base = element.attribute("base");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DIAGCLASS") {
                auto o = QSharedPointer<CDDDbDIAGCLASS>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDiagclasss.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "DIAGINST") {
                auto o = QSharedPointer<CDDDbDIAGINST>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDiaginsts.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "DIAGINSTREF") {
                auto o = QSharedPointer<CDDDbDIAGINSTREF>::create();
                if (o) {
                    o->load(childElement);
                    m_elDiaginstrefs.append(o);
                }
            } else if (elementName == "DIDREFS") {
                m_elDidrefs = QSharedPointer<CDDDbDIDREFS>::create();
                if (m_elDidrefs) {
                    m_elDidrefs->load(childElement);
                }
            } else if (elementName == "JOBCNR") {
                auto o = QSharedPointer<CDDDbJOBCNR>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elJobcnrs.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "JOBCNRREF") {
                auto o = QSharedPointer<CDDDbJOBCNRREF>::create();
                if (o) {
                    o->load(childElement);
                    m_elJobcnrrefs.append(o);
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
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
