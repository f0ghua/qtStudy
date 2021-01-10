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

bool CDDDbECUDoc::load(const QDomElement &element)
{
    bool ret = true;

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
            QLOG_TRACE() << "CDDDbECUDoc::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ATTRCATS") {

        } else if (childElement.tagName() == "DEFATTS") {

        } else if (childElement.tagName() == "DATATYPES") {

        } else if (childElement.tagName() == "DOCTMPL") {

        } else if (childElement.tagName() == "RECORDTMPLS") {

        } else if (childElement.tagName() == "DIDS") {

        } else if (childElement.tagName() == "PROTOCOLSERVICES") {

        } else if (childElement.tagName() == "DCLTMPLS") {

        } else if (childElement.tagName() == "RECORDDTPOOL") {

        } else if (childElement.tagName() == "ECU") {

        }

        child = child.nextSibling();
    }

    return ret;
}

} // namespace cdd
} // namespace vector
