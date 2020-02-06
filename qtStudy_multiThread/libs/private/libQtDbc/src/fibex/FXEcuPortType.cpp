#include "FXEcuPortType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXEcuPortType::FXEcuPortType()
{
}

void FXEcuPortType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXEcuPortType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:FRAME-TRIGGERING-REF") {
            m_frameTriggeringRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXEcuPortType::load, m_frameTriggeringRef =" << m_frameTriggeringRef;
#endif
        } else if (childElement.tagName() == "fx:INCLUDED-PDUS") {
            QDomNode pduChild = child.firstChild();
            while (!pduChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXEcuPortType::load INCLUDED-PDU" << childElement.tagName();
#endif
                if (pduChild.toElement().tagName() == "fx:INCLUDED-PDU") {
                    FXIncludedPduType pdu;
                    pdu.load(pduChild.toElement());
                    m_includedPduList.append(pdu);
                }
                pduChild = pduChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:COMPLETE-FRAME") {
            m_completeFrame = true;
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
