#include "CDDDbDCLTMPL.h"

#include "CDDDbDCLTMPLS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDCLTMPLS::CDDDbDCLTMPLS()
{
}

CDDDbDCLTMPLS::~CDDDbDCLTMPLS()
{
}

void CDDDbDCLTMPLS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DCLTMPL") {
            auto o = QSharedPointer<CDDDbDCLTMPL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_dcltmpls.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
