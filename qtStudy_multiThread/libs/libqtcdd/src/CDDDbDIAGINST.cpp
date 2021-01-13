#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSERVICE.h"
#include "CDDDbSIMPLECOMPCONT.h"
#include "CDDDbSTATICVALUE.h"

#include "CDDDbDIAGINST.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGINST::CDDDbDIAGINST()
{
}

CDDDbDIAGINST::~CDDDbDIAGINST()
{
}

void CDDDbDIAGINST::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_req = element.attribute("req");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");
    m_xauth = element.attribute("xauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "SERVICE") {
            auto o = QSharedPointer<CDDDbSERVICE>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_services.insert(o->m_id, o);
                }
            }
        } else if (elementName == "SIMPLECOMPCONT") {
            auto o = QSharedPointer<CDDDbSIMPLECOMPCONT>::create();
            if (o) {
                o->load(childElement);
                m_simplecompconts.append(o);
            }
        } else if (elementName == "STATICVALUE") {
            m_staticvalue = QSharedPointer<CDDDbSTATICVALUE>::create();
            if (m_staticvalue) {
                m_staticvalue->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
