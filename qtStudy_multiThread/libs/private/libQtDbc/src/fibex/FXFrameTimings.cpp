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

        } else if (childElement.tagName() == "fx:ABSOLUTELY-SCHEDULED-TIMING") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
