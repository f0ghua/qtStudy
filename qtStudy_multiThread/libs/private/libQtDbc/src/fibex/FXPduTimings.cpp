#include "FXPduTimings.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXPduTimings::FXPduTimings()
{
}

void FXPduTimings::load(const QDomElement &element)
{
    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXPduTimings::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:CYCLIC-TIMING") {

        } else if (childElement.tagName() == "fx:EVENT-CONTROLLED-TIMING") {

        } else if (childElement.tagName() == "fx:REQUEST-CONTROLLED-TIMING") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
