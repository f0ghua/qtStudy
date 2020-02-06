#include "FRControllerType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FRControllerType::FRControllerType()
    : FXControllerType()
{
}

void FRControllerType::load(const QDomElement &element)
{
    FXControllerType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FRControllerType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "flexray:KEY-SLOT-USAGE") {
            m_keySlotUsage.load(childElement);
        } else if (childElement.tagName() == "flexray:MAX-DYNAMIC-PAYLOAD-LENGTH") {
            m_maxDynamicPayloadLength = childElement.text().toUShort();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FRControllerType::load, m_maxDynamicPayloadLength =" << m_maxDynamicPayloadLength;
#endif
        }

        child = child.nextSibling();
    }


}

} // FIBEX
} // ASAM
