#include "FXCodingType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

CodingType::CodingType(FXFibex *fibex, QObject *parent)
    : FXRevisedElementType()
    , QObject(parent)
    , m_fibex(fibex)
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
            if (!m_codedType) {
                m_codedType = new HOCodedType(m_fibex, this);
                m_codedType->load(childElement);
            }
        } else if (childElement.tagName() == "ho:COMPU-METHODS") {
            if (!m_compuMethods) {
                m_compuMethods = new HOCompuMethods(m_fibex, this);
                m_compuMethods->load(childElement);
            }
        } else if (childElement.tagName() == "fx:MANUFACTURER-EXTENSION") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
