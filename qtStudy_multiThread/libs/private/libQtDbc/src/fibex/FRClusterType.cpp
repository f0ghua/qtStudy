#include "FRClusterType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FRClusterType::FRClusterType()
    : FXClusterType()
{
}

void FRClusterType::load(const QDomElement &element)
{
    FXClusterType::load(element);

    /* read childs */
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FRClusterType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "flexray:COLD-START-ATTEMPTS") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
