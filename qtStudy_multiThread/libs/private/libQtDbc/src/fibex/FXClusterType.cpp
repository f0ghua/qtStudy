#include "FXClusterType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXClusterType::FXClusterType()
    : FXRevisedElementType()
{
}

//
void FXClusterType::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXClusterType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:SPEED") {

        } else if (childElement.tagName() == "fx:IS-HIGH-LOW-BIT-ORDER") {

        } else if (childElement.tagName() == "fx:BIT-COUNTING-POLICY") {

        } else if (childElement.tagName() == "fx:PROTOCOL") {

        } else if (childElement.tagName() == "fx:PROTOCOL-VERSION") {

        } else if (childElement.tagName() == "fx:PHYSICAL") {

        } else if (childElement.tagName() == "fx:PHYSICAL-VERSION") {

        } else if (childElement.tagName() == "fx:CHANNEL-REFS") {

        } else if (childElement.tagName() == "fx:MEDIUM") {

        } else if (childElement.tagName() == "fx:NUMBER-OF-CYCLES") {

        } else if (childElement.tagName() == "fx:MAX-FRAME-LENGTH") {

        } else if (childElement.tagName() == "fx:CAN-FD-SPEED") {

        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
