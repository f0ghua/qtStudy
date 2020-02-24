#include "HOScaleConstr.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOScaleConstr::HOScaleConstr()
    : m_lowerLimit(0.0)
    , m_lowerLimitIntervalType(FibexTypes::HOIntervalTypeAb::CLOSED)
    , m_upperLimit(0.0)
    , m_upperLimitIntervalType(FibexTypes::HOIntervalTypeAb::CLOSED)
{
}

void HOScaleConstr::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOScaleConstr::load" << childElement.tagName();
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
                QLOG_DEBUG() << "HOScaleConstr::load, m_lowerLimitIntervalType =" << typeStr << (int)m_lowerLimitIntervalType;
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
                QLOG_DEBUG() << "HOScaleConstr::load, m_upperLimitIntervalType =" << typeStr << (int)m_upperLimitIntervalType;
#endif
            }

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
