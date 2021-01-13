#include "CDDDbSPECIFICSNAPSHOTRECORD.h"

#include "CDDDbSNAPSHOTRECORDS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSNAPSHOTRECORDS::CDDDbSNAPSHOTRECORDS()
{
}

CDDDbSNAPSHOTRECORDS::~CDDDbSNAPSHOTRECORDS()
{
}

void CDDDbSNAPSHOTRECORDS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "SPECIFICSNAPSHOTRECORD") {
            m_specificsnapshotrecord = QSharedPointer<CDDDbSPECIFICSNAPSHOTRECORD>::create();
            if (m_specificsnapshotrecord) {
                m_specificsnapshotrecord->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
