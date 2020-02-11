#include "HOUnit.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOUnit::HOUnit()
{
}

void HOUnit::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "HOUnit::load, m_id =" << m_id;
#endif

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOUnit::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:DISPLAY-NAME") {
            m_displayName = childElement.text();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOUnit::load, m_displayName =" << m_displayName;
#endif
        } else if (childElement.tagName() == "ho:FACTOR-SI-TO-UNIT") {
            m_factorSiToUnit = childElement.text().toDouble();
        } else if (childElement.tagName() == "ho:OFFSET-SI-TO-UNIT") {
            m_offsetSiToUnit = childElement.text().toDouble();
        } else if (childElement.tagName() == "ho:PHYSICAL-DIMENSION-REF") {
            m_physicalDimensionRef = childElement.attribute("ID-REF");
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
