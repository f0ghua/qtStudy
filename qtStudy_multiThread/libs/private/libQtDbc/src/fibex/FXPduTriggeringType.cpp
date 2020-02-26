#include "FXPduTriggeringType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXPduTriggeringType::FXPduTriggeringType(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
{
}

void FXPduTriggeringType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "FXPduTriggeringType::load, m_id =" << m_id;
#endif

    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXPduTriggeringType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:TIMINGS") {
            if (!m_timings) {
                m_timings = new FXPduTimings(m_fibex, this);
                m_timings->load(childElement);
            }
        } else if (childElement.tagName() == "fx:PDU-REF") {
            m_pduRef = childElement.attribute("ID-REF");
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM

