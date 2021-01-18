#include "CDDDbNAME.h"
#include "CDDDbNEGRESCODEPROXY.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATE.h"

#include "CDDDbSTATEGROUPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATEGROUPImpl::CDDDbSTATEGROUPImpl()
{
}

CDDDbSTATEGROUPImpl::~CDDDbSTATEGROUPImpl()
{
}

void CDDDbSTATEGROUPImpl::load(const QDomElement &element)
{
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
            } else if (elementName == "NEGRESCODEPROXY") {
                auto o = QSharedPointer<CDDDbNEGRESCODEPROXY>::create();
                if (o) {
                    o->load(childElement);
                    m_elNegrescodeproxys.append(o);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "STATE") {
                auto o = QSharedPointer<CDDDbSTATE>::create();
                if (o) {
                    o->load(childElement);
                    m_elStates.append(o);
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
