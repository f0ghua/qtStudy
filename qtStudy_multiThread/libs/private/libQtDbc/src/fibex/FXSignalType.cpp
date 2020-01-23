#include "FXSignalType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXSignalType::FXSignalType()
    : FXRevisedElementType()
    , m_defaultValue()
    , m_codingRef()
    , m_sigType()
    , m_priority()
{
}

void FXSignalType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "FXSignalType::load, m_id =" << m_id;
#endif
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXSignalType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:DEFAULT-VALUE") {
            m_defaultValue.append(childElement.text().toDouble());
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
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
