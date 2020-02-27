#include "FXSignalType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXSignalType::FXSignalType(FXFibex *fibex)
    : FXRevisedElementType()
    , m_fibex(fibex)
    , m_defaultValue()
    , m_codingRef()
    , m_sigType()
    , m_priority()
{
}

void FXSignalType::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXSignalType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:DEFAULT-VALUE") {
            m_defaultValue = childElement.text().toDouble();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXSignalType::load, m_defaultValue =" << m_defaultValue;
#endif
        } else if (childElement.tagName() == "fx:CODING-REF") {
            m_codingRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXSignalType::load, m_codingRef =" << m_codingRef;
#endif
        } else if (childElement.tagName() == "fx:SIGNAL-TYPE") {
            m_sigType.load(childElement);
        } else if (childElement.tagName() == "fx:PRIORITY") {
            m_priority = childElement.text().toUInt();
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
