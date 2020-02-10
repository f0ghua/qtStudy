#include "HOUnitSpec.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOUnitSpec::HOUnitSpec()
{
}

void HOUnitSpec::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXProcessingInformation::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:ADMIN-DATA") {

        } else if (childElement.tagName() == "ho:PHYSICAL-DIMENSIONS") {

        } else if (childElement.tagName() == "ho:UNITGROUPS") {

        } else if (childElement.tagName() == "ho:UNITS") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
