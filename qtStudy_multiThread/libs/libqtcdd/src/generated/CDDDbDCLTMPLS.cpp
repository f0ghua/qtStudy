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
    CDDDbDCLTMPLSImpl::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DCLTMPL") {
                auto o = QSharedPointer<CDDDbDCLTMPL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDcltmplVector.append(o);
                    }
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
