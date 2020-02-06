#include "ConnectorType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXConnectorType::FXConnectorType()
{
}

void FXConnectorType::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXConnectorType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:CHANNEL-REF") {
            m_channelRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXConnectorType::load, m_channelRef =" << m_channelRef;
#endif
        } else if (childElement.tagName() == "fx:CONTROLLER-REF") {
            m_controllerRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXConnectorType::load, m_controllerRef =" << m_controllerRef;
#endif
        } else if (childElement.tagName() == "fx:INPUTS") {

        } else if (childElement.tagName() == "fx:OUTPUTS") {

        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
