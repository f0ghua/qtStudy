#include "CDDDbDIDCOMMONSNAPSHOTDATA.h"

#include "CDDDbCOMMONSNAPSHOTDATAPOOLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMMONSNAPSHOTDATAPOOLImpl::CDDDbCOMMONSNAPSHOTDATAPOOLImpl()
{
}

CDDDbCOMMONSNAPSHOTDATAPOOLImpl::~CDDDbCOMMONSNAPSHOTDATAPOOLImpl()
{
}

void CDDDbCOMMONSNAPSHOTDATAPOOLImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DIDCOMMONSNAPSHOTDATA") {
                m_elDidcommonsnapshotdata = QSharedPointer<CDDDbDIDCOMMONSNAPSHOTDATA>::create();
                if (m_elDidcommonsnapshotdata) {
                    m_elDidcommonsnapshotdata->load(childElement);
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
