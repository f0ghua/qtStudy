#include "CDDDbSPECIFICSNAPSHOTRECORD.h"

#include "CDDDbSNAPSHOTRECORDSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSNAPSHOTRECORDSImpl::CDDDbSNAPSHOTRECORDSImpl()
{
}

CDDDbSNAPSHOTRECORDSImpl::~CDDDbSNAPSHOTRECORDSImpl()
{
}

void CDDDbSNAPSHOTRECORDSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "SPECIFICSNAPSHOTRECORD") {
                m_elSpecificsnapshotrecord = QSharedPointer<CDDDbSPECIFICSNAPSHOTRECORD>::create();
                if (m_elSpecificsnapshotrecord) {
                    m_elSpecificsnapshotrecord->load(childElement);
                }
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
