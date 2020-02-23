#include "FXEcuType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXEcuType::FXEcuType(FXFibex *fibex, QObject *parent)
    : FXRevisedElementType()
    , QObject(parent)
    , m_fibex(fibex)
{
}

void FXEcuType::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXEcuType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:DIAGNOSTIC-ADDRESSES") {
#ifndef F_NO_DEBUG
            //QLOG_DEBUG() << "FXEcuType::load, m_byteLength =" << m_byteLength;
#endif
        } else if (childElement.tagName() == "fx:FUNCTION-REFS") {

        } else if (childElement.tagName() == "fx:CONTROLLERS") {
            QDomNode subChild = child.firstChild();
            while (!subChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXEcuType::load CONTROLLERS" << childElement.tagName();
#endif
                if (subChild.toElement().tagName() == "fx:CONTROLLER") {
                    FRControllerType c;
                    c.load(subChild.toElement());
                    m_controllerList.append(c);
                }
                subChild = subChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:CONNECTORS") {
            QDomNode subChild = child.firstChild();
            while (!subChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXEcuType::load CONNECTORS" << childElement.tagName();
#endif
                if (subChild.toElement().tagName() == "fx:CONNECTOR") {
                    FRConnectorType c;
                    c.load(subChild.toElement());
                    m_connectorList.append(c);
                }
                subChild = subChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
