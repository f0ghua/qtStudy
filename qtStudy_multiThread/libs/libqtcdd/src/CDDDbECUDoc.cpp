#include "CDDDbAttrCats.h"
#include "CDDDbECU.h"
#include "CDDLog.h"

#include "CDDDbECUDoc.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECUDoc::CDDDbECUDoc()
{
}

CDDDbECUDoc::~CDDDbECUDoc()
{

}

void CDDDbECUDoc::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
            QLOG_TRACE() << "CDDDbECUDoc::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ATTRCATS") {
            m_attrcats = QSharedPointer<CDDDbAttrCats>::create();
            m_attrcats->load(childElement);
        } else if (childElement.tagName() == "DEFATTS") {

        } else if (childElement.tagName() == "DATATYPES") {

        } else if (childElement.tagName() == "DOCTMPL") {

        } else if (childElement.tagName() == "RECORDTMPLS") {

        } else if (childElement.tagName() == "DIDS") {

        } else if (childElement.tagName() == "PROTOCOLSERVICES") {

        } else if (childElement.tagName() == "DCLTMPLS") {

        } else if (childElement.tagName() == "RECORDDTPOOL") {

        } else if (childElement.tagName() == "ECU") {
            m_ecu = QSharedPointer<CDDDbECU>::create();
            m_ecu->load(childElement);
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
