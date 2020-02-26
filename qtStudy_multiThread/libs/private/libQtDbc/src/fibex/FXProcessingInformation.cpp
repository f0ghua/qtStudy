#include "FXProcessingInformation.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXProcessingInformation::FXProcessingInformation(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
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
            if (!m_unitSpec) {
                m_unitSpec = new HOUnitSpec(m_fibex, this);
                m_unitSpec->load(childElement);
            }
        } else if (childElement.tagName() == "fx:CODINGS") {
            if (!m_codings) {
                m_codings = new FXCodings(m_fibex, this);
                m_codings->load(childElement);
            }
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
