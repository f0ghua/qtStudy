#include "HOCompuScale.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompuScale::HOCompuScale(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
{
}

void HOCompuScale::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompuScale::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:SHORT-LABEL") {

        } else if (childElement.tagName() == "ho:DESC") {

        } else if (childElement.tagName() == "ho:MASK") {

        } else if (childElement.tagName() == "ho:LOWER-LIMIT") {

        } else if (childElement.tagName() == "ho:UPPER-LIMIT") {

        } else if (childElement.tagName() == "ho:COMPU-CONST") {

        } else if (childElement.tagName() == "ho:COMPU-RATIONAL-COEFFS") {
            if (!m_compuRationalCoeffs) {
                m_compuRationalCoeffs = new HOCompuRationalCoeffs(m_fibex, this);
                m_compuRationalCoeffs->load(childElement);
            }
        } else if (childElement.tagName() == "ho:COMPU-GENERIC-MATH") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
