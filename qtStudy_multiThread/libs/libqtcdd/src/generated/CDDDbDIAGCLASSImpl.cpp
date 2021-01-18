#include "CDDDbDESC.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbDIAGINSTREF.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIAGCLASSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGCLASSImpl::CDDDbDIAGCLASSImpl()
{
}

CDDDbDIAGCLASSImpl::~CDDDbDIAGCLASSImpl()
{
}

void CDDDbDIAGCLASSImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");

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
