#include "CDDDbCSTRDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbSHPROXYATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHPROXYATTS::CDDDbSHPROXYATTS()
{
}

CDDDbSHPROXYATTS::~CDDDbSHPROXYATTS()
{
}

void CDDDbSHPROXYATTS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "CSTRDEF") {
            m_cstrdef = QSharedPointer<CDDDbCSTRDEF>::create();
            if (m_cstrdef) {
                m_cstrdef->load(childElement);
            }
        } else if (elementName == "STRDEF") {
            m_strdef = QSharedPointer<CDDDbSTRDEF>::create();
            if (m_strdef) {
                m_strdef->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
