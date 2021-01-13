#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMPREF.h"

#include "CDDDbSHSTATIC.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHSTATIC::CDDDbSHSTATIC()
{
}

CDDDbSHSTATIC::~CDDDbSHSTATIC()
{
}

void CDDDbSHSTATIC::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
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
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "STATICCOMPREF") {
            auto o = QSharedPointer<CDDDbSTATICCOMPREF>::create();
            if (o) {
                o->load(childElement);
                m_staticcomprefs.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
