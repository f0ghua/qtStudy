#include "HOScaleConstrType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOScaleConstrType::HOScaleConstrType()
{
}

void HOScaleConstrType::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOScaleConstrType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:LOWER-LIMIT") {
            m_lowerLimit = childElement.text().toDouble();
            QString typeStr = childElement.attribute("INTERVAL-TYPE");
            FibexTypes::EnumParser<FibexTypes::HOIntervalTypeAb> ep;
            FibexTypes::HOIntervalTypeAb type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_lowerLimitIntervalType = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "HOScaleConstrType::load, m_lowerLimitIntervalType =" << typeStr << (int)m_lowerLimitIntervalType;
#endif
            }
        } else if (childElement.tagName() == "ho:UPPER-LIMIT") {
            m_upperLimit = childElement.text().toDouble();
            QString typeStr = childElement.attribute("INTERVAL-TYPE");
            FibexTypes::EnumParser<FibexTypes::HOIntervalTypeAb> ep;
            FibexTypes::HOIntervalTypeAb type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_upperLimitIntervalType = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "HOScaleConstrType::load, m_upperLimitIntervalType =" << typeStr << (int)m_upperLimitIntervalType;
#endif
            }

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
