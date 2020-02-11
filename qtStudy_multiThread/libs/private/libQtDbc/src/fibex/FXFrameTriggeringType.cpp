#include "FXFrameTriggeringType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXFrameTriggeringType::FXFrameTriggeringType()
{
}

void FXFrameTriggeringType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "FrameTriggeringType::load, m_id =" << m_id;
#endif

    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FrameTriggeringType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:TIMINGS") {

        } else if (childElement.tagName() == "fx:IDENTIFIER") {

        } else if (childElement.tagName() == "fx:FRAME-REF") {

        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
