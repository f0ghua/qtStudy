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
        if (childElement.tagName() == "fx:PROCESSING-INFORMATION") {
//            if (!m_processingInformation) {
//                m_processingInformation = new FXProcessingInformation(this);
//                m_processingInformation->load(childElement);
//            }
        } else if (childElement.tagName() == "fx:ELEMENTS") {

        } else if (childElement.tagName() == "fx:PROJECT") {

        } else if (childElement.tagName() == "fx:PROTOCOLS") {

        } else if (childElement.tagName() == "fx:REQUIREMENTS") {

        }

        child = child.nextSibling();
    }

    return ret;
}

} // namespace cdd
} // namespace vector
