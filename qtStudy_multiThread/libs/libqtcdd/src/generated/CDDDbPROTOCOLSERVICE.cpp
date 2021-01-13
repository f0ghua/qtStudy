#include "CDDDbNAME.h"
#include "CDDDbNEG.h"
#include "CDDDbNEGRESCODEPROXIES.h"
#include "CDDDbPOS.h"
#include "CDDDbQUAL.h"
#include "CDDDbREQ.h"

#include "CDDDbPROTOCOLSERVICE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICE::CDDDbPROTOCOLSERVICE()
{
}

CDDDbPROTOCOLSERVICE::~CDDDbPROTOCOLSERVICE()
{
}

void CDDDbPROTOCOLSERVICE::load(const QDomElement &element)
{
    m_func = element.attribute("func");
    m_id = element.attribute("id");
    m_mresp = element.attribute("mresp");
    m_oid = element.attribute("oid");
    m_phys = element.attribute("phys");
    m_respOnFunc = element.attribute("respOnFunc");
    m_respOnPhys = element.attribute("respOnPhys");
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
        } else if (elementName == "NEG") {
            m_neg = QSharedPointer<CDDDbNEG>::create();
            if (m_neg) {
                m_neg->load(childElement);
            }
        } else if (elementName == "NEGRESCODEPROXIES") {
            m_negrescodeproxies = QSharedPointer<CDDDbNEGRESCODEPROXIES>::create();
            if (m_negrescodeproxies) {
                m_negrescodeproxies->load(childElement);
            }
        } else if (elementName == "POS") {
            m_pos = QSharedPointer<CDDDbPOS>::create();
            if (m_pos) {
                m_pos->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "REQ") {
            m_req = QSharedPointer<CDDDbREQ>::create();
            if (m_req) {
                m_req->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
