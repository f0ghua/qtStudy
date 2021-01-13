#include "CDDDbTUV.h"

#include "CDDDbSHORTCUTNAME.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTCUTNAME::CDDDbSHORTCUTNAME()
{
}

CDDDbSHORTCUTNAME::~CDDDbSHORTCUTNAME()
{
}

void CDDDbSHORTCUTNAME::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "TUV") {
            m_tuv = QSharedPointer<CDDDbTUV>::create();
            if (m_tuv) {
                m_tuv->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
