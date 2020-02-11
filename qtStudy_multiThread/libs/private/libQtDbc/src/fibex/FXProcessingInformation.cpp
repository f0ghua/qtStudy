#include "FXProcessingInformation.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXProcessingInformation::FXProcessingInformation()
{
}

void FXProcessingInformation::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXProcessingInformation::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:UNIT-SPEC") {
            m_unitSpec.load(childElement);
        } else if (childElement.tagName() == "fx:CODINGS") {
            m_codings.load(childElement);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
