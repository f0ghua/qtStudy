#include "CDDDbDIDCOMMONSNAPSHOTDATA.h"

#include "CDDDbCOMMONSNAPSHOTDATAPOOL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMMONSNAPSHOTDATAPOOL::CDDDbCOMMONSNAPSHOTDATAPOOL()
{
}

CDDDbCOMMONSNAPSHOTDATAPOOL::~CDDDbCOMMONSNAPSHOTDATAPOOL()
{
}

void CDDDbCOMMONSNAPSHOTDATAPOOL::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DIDCOMMONSNAPSHOTDATA") {
            m_didcommonsnapshotdata = QSharedPointer<CDDDbDIDCOMMONSNAPSHOTDATA>::create();
            if (m_didcommonsnapshotdata) {
                m_didcommonsnapshotdata->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
