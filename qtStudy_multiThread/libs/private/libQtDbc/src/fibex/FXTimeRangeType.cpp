#include "FXTimeRangeType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

TimeRangeType::TimeRangeType()
{
}

void TimeRangeType::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXRequestControlledTimingType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:VALUE") {

        } else if (childElement.tagName() == "fx:TOLERANCE") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM