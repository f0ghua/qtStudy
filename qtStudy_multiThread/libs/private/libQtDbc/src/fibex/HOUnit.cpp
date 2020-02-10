#include "HOUnit.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

Unit::Unit()
{
}

void Unit::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXProcessingInformation::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:DISPLAY-NAME") {

        } else if (childElement.tagName() == "ho:FACTOR-SI-TO-UNIT") {

        } else if (childElement.tagName() == "ho:OFFSET-SI-TO-UNIT") {

        } else if (childElement.tagName() == "ho:PHYSICAL-DIMENSION-REF") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
