#include "CDDDbCSTRDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbDIDATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDATTS::CDDDbDIDATTS()
{
}

CDDDbDIDATTS::~CDDDbDIDATTS()
{
}

void CDDDbDIDATTS::load(const QDomElement &element)
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
        } else if (elementName == "UNSDEF") {
            m_unsdef = QSharedPointer<CDDDbUNSDEF>::create();
            if (m_unsdef) {
                m_unsdef->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
