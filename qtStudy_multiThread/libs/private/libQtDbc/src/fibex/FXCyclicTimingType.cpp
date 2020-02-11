#include "FXCyclicTimingType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXCyclicTimingType::FXCyclicTimingType()
{
}

void FXCyclicTimingType::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXPduTimings::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:REPEATING-TIME-RANGE") {

        } else if (childElement.tagName() == "fx:STARTING-TIME-RANGE") {

        } else if (childElement.tagName() == "fx:ACTIVE-CONDITION") {

        } else if (childElement.tagName() == "fx:START-CONDITION") {

        } else if (childElement.tagName() == "fx:STOP-CONDITION") {

        } else if (childElement.tagName() == "fx:FINAL-REPETITIONS") {

        } else if (childElement.tagName() == "ho:DESC") {

        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
