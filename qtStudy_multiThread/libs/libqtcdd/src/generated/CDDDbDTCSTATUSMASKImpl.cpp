#include "CDDDbDTCSTATUSBITGROUP.h"

#include "CDDDbDTCSTATUSMASKImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDTCSTATUSMASKImpl::CDDDbDTCSTATUSMASKImpl()
{
}

CDDDbDTCSTATUSMASKImpl::~CDDDbDTCSTATUSMASKImpl()
{
}

void CDDDbDTCSTATUSMASKImpl::load(const QDomElement &element)
{
    m_dtref = element.attribute("dtref");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DTCSTATUSBITGROUP") {
                auto o = QSharedPointer<CDDDbDTCSTATUSBITGROUP>::create();
                if (o) {
                    o->load(childElement);
                    m_elDtcstatusbitgroups.append(o);
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
