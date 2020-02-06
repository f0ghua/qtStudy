#include "FXIncludedPduType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXIncludedPduType::FXIncludedPduType()
{
}

void FXIncludedPduType::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXIncludedPduType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:PDU-TRIGGERING-REF") {
            m_pduTriggeringRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXIncludedPduType::load, m_pduTriggeringRef =" << m_pduTriggeringRef;
#endif
        } else if (childElement.tagName() == "fx:INCLUDED-SIGNALS") {
            QDomNode sigChild = child.firstChild();
            while (!sigChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXIncludedPduType::load INCLUDED-SIGNALS" << childElement.tagName();
#endif
                if (sigChild.toElement().tagName() == "fx:INCLUDED-SIGNAL") {
                    FXIncludedSignalType sig;
                    sig.load(sigChild.toElement());
                    m_includedSignalList.append(sig);
                }
                sigChild = sigChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:COMPLETE-PDU") {
            m_completePdu = true;
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
