#include "CDDDbENUM.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHORTCUTNAME.h"
#include "CDDDbSHORTCUTQUAL.h"

#include "CDDDbSERVICE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSERVICE::CDDDbSERVICE()
{
}

CDDDbSERVICE::~CDDDbSERVICE()
{
}

void CDDDbSERVICE::load(const QDomElement &element)
{
    m_func = element.attribute("func");
    m_id = element.attribute("id");
    m_mayBeExec = element.attribute("mayBeExec");
    m_oid = element.attribute("oid");
    m_phys = element.attribute("phys");
    m_req = element.attribute("req");
    m_respOnFunc = element.attribute("respOnFunc");
    m_respOnPhys = element.attribute("respOnPhys");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");
    m_trans = element.attribute("trans");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ENUM") {
            m_enum = QSharedPointer<CDDDbENUM>::create();
            if (m_enum) {
                m_enum->load(childElement);
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
        } else if (elementName == "SHORTCUTNAME") {
            m_shortcutname = QSharedPointer<CDDDbSHORTCUTNAME>::create();
            if (m_shortcutname) {
                m_shortcutname->load(childElement);
            }
        } else if (elementName == "SHORTCUTQUAL") {
            m_shortcutqual = QSharedPointer<CDDDbSHORTCUTQUAL>::create();
            if (m_shortcutqual) {
                m_shortcutqual->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
