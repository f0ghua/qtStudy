#include "FXCodingType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

CodingType::CodingType()
    : FXRevisedElementType()
{
}

void CodingType::load(const QDomElement &element)
{
    FXRevisedElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CodingType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:PHYSICAL-TYPE") {

        } else if (childElement.tagName() == "ho:CODED-TYPE") {
            m_codedType.load(childElement);
        } else if (childElement.tagName() == "ho:COMPU-METHODS") {
            m_compuMethods.load(childElement);
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
