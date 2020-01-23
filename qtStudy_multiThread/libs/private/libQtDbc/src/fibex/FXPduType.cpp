#include "FXPduType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXPduTypeCt::FXPduTypeCt()
    : FXRevisedElementType()
{
}

void FXPduTypeCt::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXPduTypeCt::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:BYTE-LENGTH") {
            m_byteLength = childElement.text().toUInt();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXPduTypeCt::load, m_byteLength =" << m_byteLength;
#endif
        } else if (childElement.tagName() == "fx:PDU-TYPE") {
            QString typeStr = childElement.text();
            FibexTypes::EnumParser<FibexTypes::FXPduTypeSt> ep;
            FibexTypes::FXPduTypeSt type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_pduType = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "FXPduTypeCt::load, m_pduType =" << typeStr << (int)m_pduType;
#endif
            }
        } else if (childElement.tagName() == "fx:SIGNAL-INSTANCES") {
            m_sigInstances.load(childElement);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
