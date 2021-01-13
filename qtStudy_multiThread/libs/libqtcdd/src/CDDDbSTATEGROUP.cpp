#include "CDDDbNAME.h"
#include "CDDDbNEGRESCODEPROXY.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATE.h"

#include "CDDDbSTATEGROUP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATEGROUP::CDDDbSTATEGROUP()
{
}

CDDDbSTATEGROUP::~CDDDbSTATEGROUP()
{
}

void CDDDbSTATEGROUP::load(const QDomElement &element)
{
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
        } else if (elementName == "NEGRESCODEPROXY") {
            m_negrescodeproxy = QSharedPointer<CDDDbNEGRESCODEPROXY>::create();
            if (m_negrescodeproxy) {
                m_negrescodeproxy->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "STATE") {
            auto o = QSharedPointer<CDDDbSTATE>::create();
            if (o) {
                o->load(childElement);
                m_states.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
