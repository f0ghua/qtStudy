#include "FXSignalInstances.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXSignalInstances::FXSignalInstances()
{
}

void FXSignalInstances::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXSignalInstances::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:SIGNAL-INSTANCE") {
            FXSignalInstanceType si;
            si.load(childElement);
            m_sigInstanceList.append(si);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
