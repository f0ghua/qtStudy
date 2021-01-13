#include "CDDDbEXTENDEDDATARECORD.h"

#include "CDDDbEXTENDEDDATARECORDS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEXTENDEDDATARECORDS::CDDDbEXTENDEDDATARECORDS()
{
}

CDDDbEXTENDEDDATARECORDS::~CDDDbEXTENDEDDATARECORDS()
{
}

void CDDDbEXTENDEDDATARECORDS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "EXTENDEDDATARECORD") {
            m_extendeddatarecord = QSharedPointer<CDDDbEXTENDEDDATARECORD>::create();
            if (m_extendeddatarecord) {
                m_extendeddatarecord->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
