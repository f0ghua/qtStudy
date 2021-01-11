#include "CDDLog.h"
#include "CDDDbECU.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECU::CDDDbECU()
{
}

CDDDbECU::~CDDDbECU()
{

}

void CDDDbECU::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
            QLOG_TRACE() << "CDDDbECU::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "NAME") {

        } else if (childElement.tagName() == "DESC") {

        } else if (childElement.tagName() == "UNS") {

        } else if (childElement.tagName() == "ENUM") {

        } else if (childElement.tagName() == "CSTR") {

        } else if (childElement.tagName() == "FAULTMEMORY") {

        } else if (childElement.tagName() == "VAR") {

        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
