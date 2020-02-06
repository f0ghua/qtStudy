#include "FXCodings.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXCodings::FXCodings()
{
}

void FXCodings::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXCodings::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:CODING") {
            CodingType ct;
            ct.load(childElement);
            m_codingList.append(ct);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
