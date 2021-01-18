#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbNEG.h"
#include "CDDDbNEGRESCODEPROXIES.h"
#include "CDDDbPOS.h"
#include "CDDDbQUAL.h"
#include "CDDDbREQ.h"

#include "CDDDbPROTOCOLSERVICEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICEImpl::CDDDbPROTOCOLSERVICEImpl()
{
}

CDDDbPROTOCOLSERVICEImpl::~CDDDbPROTOCOLSERVICEImpl()
{
}

void CDDDbPROTOCOLSERVICEImpl::load(const QDomElement &element)
{
    m_func = element.attribute("func");
    m_id = element.attribute("id");
    m_maycombcont = element.attribute("maycombcont");
    m_mresp = element.attribute("mresp");
    m_oid = element.attribute("oid");
    m_periodicresp = element.attribute("periodicresp");
    m_phys = element.attribute("phys");
    m_respOnFunc = element.attribute("respOnFunc");
    m_respOnPhys = element.attribute("respOnPhys");
    m_sprmibonfunc = element.attribute("sprmibonfunc");
    m_sprmibonphys = element.attribute("sprmibonphys");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "NEG") {
                m_elNeg = QSharedPointer<CDDDbNEG>::create();
                if (m_elNeg) {
                    m_elNeg->load(childElement);
                }
            } else if (elementName == "NEGRESCODEPROXIES") {
                m_elNegrescodeproxies = QSharedPointer<CDDDbNEGRESCODEPROXIES>::create();
                if (m_elNegrescodeproxies) {
                    m_elNegrescodeproxies->load(childElement);
                }
            } else if (elementName == "POS") {
                m_elPos = QSharedPointer<CDDDbPOS>::create();
                if (m_elPos) {
                    m_elPos->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
                }
            } else if (elementName == "REQ") {
                m_elReq = QSharedPointer<CDDDbREQ>::create();
                if (m_elReq) {
                    m_elReq->load(childElement);
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
