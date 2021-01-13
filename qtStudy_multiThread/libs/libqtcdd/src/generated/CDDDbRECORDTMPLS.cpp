#include "CDDDbRECORDTMPL.h"

#include "CDDDbRECORDTMPLS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDTMPLS::CDDDbRECORDTMPLS()
{
}

CDDDbRECORDTMPLS::~CDDDbRECORDTMPLS()
{
}

void CDDDbRECORDTMPLS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "RECORDTMPL") {
            m_recordtmpl = QSharedPointer<CDDDbRECORDTMPL>::create();
            if (m_recordtmpl) {
                m_recordtmpl->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
