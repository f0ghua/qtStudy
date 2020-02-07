#include "HOCompuScale.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompuScale::HOCompuScale()
{
}

void HOCompuScale::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompuScale::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:SHORT-LABEL") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
