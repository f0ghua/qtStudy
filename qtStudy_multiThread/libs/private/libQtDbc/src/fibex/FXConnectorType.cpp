#include "FXConnectorType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXConnectorType::FXConnectorType()
{
}

void FXConnectorType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_TRACE() << "FXConnectorType::load m_id =" << m_id;
#endif

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXConnectorType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:CHANNEL-REF") {

        } else if (childElement.tagName() == "fx:CONTROLLER-REF") {

        } else if (childElement.tagName() == "fx:INPUTS") {

        } else if (childElement.tagName() == "fx:OUTPUTS") {

        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
