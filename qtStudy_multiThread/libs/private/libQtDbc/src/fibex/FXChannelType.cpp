#include "FXChannelType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXChannelType::FXChannelType()
    : FXRevisedElementType()
{
}

void FXChannelType::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXChannelType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:PDU-TRIGGERINGS") {
            FXPduTriggeringType tr;
            tr.load(childElement);
            m_pduTriggeringList.append(tr);
        } else if (childElement.tagName() == "fx:FRAME-TRIGGERINGS") {
            FXFrameTriggeringType tr;
            tr.load(childElement);
            m_frameTriggeringList.append(tr);
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
