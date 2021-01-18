#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSERVICE.h"
#include "CDDDbSIMPLECOMPCONT.h"
#include "CDDDbSTATICVALUE.h"

#include "CDDDbDIAGINSTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGINSTImpl::CDDDbDIAGINSTImpl()
{
}

CDDDbDIAGINSTImpl::~CDDDbDIAGINSTImpl()
{
}

void CDDDbDIAGINSTImpl::load(const QDomElement &element)
{
    m_act = element.attribute("act");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_req = element.attribute("req");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");
    m_xauth = element.attribute("xauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
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
            } else if (elementName == "SERVICE") {
                auto o = QSharedPointer<CDDDbSERVICE>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elServices.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "SIMPLECOMPCONT") {
                auto o = QSharedPointer<CDDDbSIMPLECOMPCONT>::create();
                if (o) {
                    o->load(childElement);
                    m_elSimplecompconts.append(o);
                }
            } else if (elementName == "STATICVALUE") {
                m_elStaticvalue = QSharedPointer<CDDDbSTATICVALUE>::create();
                if (m_elStaticvalue) {
                    m_elStaticvalue->load(childElement);
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
