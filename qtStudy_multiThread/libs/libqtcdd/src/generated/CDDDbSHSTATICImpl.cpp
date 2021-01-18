#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATICCOMPREF.h"

#include "CDDDbSHSTATICImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHSTATICImpl::CDDDbSHSTATICImpl()
{
}

CDDDbSHSTATICImpl::~CDDDbSHSTATICImpl()
{
}

void CDDDbSHSTATICImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "STATICCOMPREF") {
                auto o = QSharedPointer<CDDDbSTATICCOMPREF>::create();
                if (o) {
                    o->load(childElement);
                    m_elStaticcomprefs.append(o);
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
