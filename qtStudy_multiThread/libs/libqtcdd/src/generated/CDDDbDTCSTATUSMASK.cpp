#include "CDDDbDTCSTATUSBITGROUP.h"

#include "CDDDbDTCSTATUSMASK.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDTCSTATUSMASK::CDDDbDTCSTATUSMASK()
{
}

CDDDbDTCSTATUSMASK::~CDDDbDTCSTATUSMASK()
{
}

void CDDDbDTCSTATUSMASK::load(const QDomElement &element)
{
    m_dtref = element.attribute("dtref");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DTCSTATUSBITGROUP") {
            auto o = QSharedPointer<CDDDbDTCSTATUSBITGROUP>::create();
            if (o) {
                o->load(childElement);
                m_dtcstatusbitgroups.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
