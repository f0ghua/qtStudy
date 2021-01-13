#include "CDDDbNAME.h"
#include "CDDDbPROXYCOMPREF.h"
#include "CDDDbQUAL.h"

#include "CDDDbSHPROXY.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHPROXY::CDDDbSHPROXY()
{
}

CDDDbSHPROXY::~CDDDbSHPROXY()
{
}

void CDDDbSHPROXY::load(const QDomElement &element)
{
    m_dest = element.attribute("dest");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "PROXYCOMPREF") {
            auto o = QSharedPointer<CDDDbPROXYCOMPREF>::create();
            if (o) {
                o->load(childElement);
                m_proxycomprefs.append(o);
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
