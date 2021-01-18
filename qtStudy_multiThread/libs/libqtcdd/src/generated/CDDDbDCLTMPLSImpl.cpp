#include "CDDDbDCLTMPL.h"

#include "CDDDbDCLTMPLSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDCLTMPLSImpl::CDDDbDCLTMPLSImpl()
{
}

CDDDbDCLTMPLSImpl::~CDDDbDCLTMPLSImpl()
{
}

void CDDDbDCLTMPLSImpl::load(const QDomElement &element)
{
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
                        m_elDcltmpls.insert(o->m_id, o);
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
