#include "FXAbsolutelyScheduledTimingType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

AbsolutelyScheduledTimingType::AbsolutelyScheduledTimingType()
{
}

void AbsolutelyScheduledTimingType::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FrameTriggeringType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:DESC") {
            m_desc = childElement.text();
        } else if (childElement.tagName() == "fx:SLOT-ID") {
            m_slotId = childElement.text().toInt();
        } else if (childElement.tagName() == "fx:CYCLE-COUNTER") {
            m_cycleCounter = childElement.text().toShort();
        } else if (childElement.tagName() == "fx:BASE-CYCLE") {
            m_baseCycle = childElement.text().toShort();
        } else if (childElement.tagName() == "fx:CYCLE-REPETITION") {
            m_cycleRepetition = childElement.text().toShort();
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM

