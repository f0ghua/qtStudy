#include "FXFrameTimings.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXFrameTimings::FXFrameTimings()
{
}

void FXFrameTimings::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FrameTriggeringType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:RELATIVELY-SCHEDULED-TIMING") {
            m_relativelyScheduledTiming.load(childElement);
        } else if (childElement.tagName() == "fx:ABSOLUTELY-SCHEDULED-TIMING") {
            m_absolutelyScheduledTiming.load(childElement);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
