#include "HOCompInternalToPhys.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompInternalToPhys::HOCompInternalToPhys()
{
}

void HOCompInternalToPhys::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompInternalToPhys::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:COMPU-SCALES") {
            m_compuScales.load(childElement);
        } else if (childElement.tagName() == "ho:COMPU-DEFAULT-VALUE") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
