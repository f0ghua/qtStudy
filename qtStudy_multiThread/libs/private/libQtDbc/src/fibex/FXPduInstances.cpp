#include "FXPduInstances.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXPduInstances::FXPduInstances()
{
}

void FXPduInstances::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXPduInstances::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:PDU-INSTANCE") {
            FXPduInstanceType pi;
            pi.load(childElement);
            m_pduInstanceList.append(pi);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
