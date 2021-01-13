#include "CDDDbETAG.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbENUMRECORDITEMTMPL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbENUMRECORDITEMTMPL::CDDDbENUMRECORDITEMTMPL()
{
}

CDDDbENUMRECORDITEMTMPL::~CDDDbENUMRECORDITEMTMPL()
{
}

void CDDDbENUMRECORDITEMTMPL::load(const QDomElement &element)
{
    m_conv = element.attribute("conv");
    m_id = element.attribute("id");
    m_mayBeDup = element.attribute("mayBeDup");
    m_oid = element.attribute("oid");
    m_sort = element.attribute("sort");
    m_temploid = element.attribute("temploid");
    m_v = element.attribute("v");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ETAG") {
            auto o = QSharedPointer<CDDDbETAG>::create();
            if (o) {
                o->load(childElement);
                m_etags.append(o);
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
