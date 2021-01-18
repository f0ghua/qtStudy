#include "CDDDbNAME.h"
#include "CDDDbPROXYCOMPREF.h"
#include "CDDDbQUAL.h"

#include "CDDDbSHPROXYImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHPROXYImpl::CDDDbSHPROXYImpl()
{
}

CDDDbSHPROXYImpl::~CDDDbSHPROXYImpl()
{
}

void CDDDbSHPROXYImpl::load(const QDomElement &element)
{
    m_dest = element.attribute("dest");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");
    m_xdtauth = element.attribute("xdtauth");

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
            } else if (elementName == "PROXYCOMPREF") {
                auto o = QSharedPointer<CDDDbPROXYCOMPREF>::create();
                if (o) {
                    o->load(childElement);
                    m_elProxycomprefs.append(o);
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
