#include "FXSignalInstanceType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXSignalInstanceType::FXSignalInstanceType(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
{
}

void FXSignalInstanceType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "FXSignalInstanceType::load, m_id =" << m_id;
#endif

    m_commLayoutDetails.load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXSignalInstanceType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:SIGNAL-REF") {
            m_sigRef.load(childElement);
        } else if (childElement.tagName() == "fx:SIGNAL-UPDATE-BIT-POSITION") {
            m_signalUpdateBitPosition = childElement.text().toUInt();
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
