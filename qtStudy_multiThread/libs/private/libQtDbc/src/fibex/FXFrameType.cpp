#include "FXFrameType.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXFrameTypeCt::FXFrameTypeCt()
    //: RevisedElementType()
{
}

void FXFrameTypeCt::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXFrameTypeCt::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:BYTE-LENGTH") {
            m_byteLength = childElement.text().toUInt();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "FXFrameTypeCt::load, m_byteLength =" << m_byteLength;
#endif
        } else if (childElement.tagName() == "fx:FRAME-TYPE") {
            QString typeStr = childElement.text();
            FibexTypes::EnumParser<FibexTypes::FXFrameTypeSt> ep;
            FibexTypes::FXFrameTypeSt type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_frameType = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "FXFrameTypeCt::load, m_frameType =" << typeStr << (int)m_frameType;
#endif
            }
        } else if (childElement.tagName() == "fx:PDU-INSTANCES") {
            m_pduInstances.load(childElement);
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

}
}
