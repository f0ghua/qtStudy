#include "CDDDbDESC.h"
#include "CDDDbDIAGINST.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDIAGCLASS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGCLASS::CDDDbDIAGCLASS()
{
}

CDDDbDIAGCLASS::~CDDDbDIAGCLASS()
{
}

void CDDDbDIAGCLASS::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DESC") {
            m_desc = QSharedPointer<CDDDbDESC>::create();
            if (m_desc) {
                m_desc->load(childElement);
            }
        } else if (elementName == "DIAGINST") {
            auto o = QSharedPointer<CDDDbDIAGINST>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_diaginsts.insert(o->m_id, o);
                }
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
