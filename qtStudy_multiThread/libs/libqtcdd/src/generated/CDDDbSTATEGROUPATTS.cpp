#include "CDDDbCSTRDEF.h"

#include "CDDDbSTATEGROUPATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATEGROUPATTS::CDDDbSTATEGROUPATTS()
{
}

CDDDbSTATEGROUPATTS::~CDDDbSTATEGROUPATTS()
{
}

void CDDDbSTATEGROUPATTS::load(const QDomElement &element)
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
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
