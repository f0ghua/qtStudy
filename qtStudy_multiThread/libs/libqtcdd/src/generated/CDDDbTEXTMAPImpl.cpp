#include "CDDDbADDINFO.h"
#include "CDDDbTEXT.h"

#include "CDDDbTEXTMAPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTEXTMAPImpl::CDDDbTEXTMAPImpl()
{
}

CDDDbTEXTMAPImpl::~CDDDbTEXTMAPImpl()
{
}

void CDDDbTEXTMAPImpl::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_s = element.attribute("s");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ADDINFO") {
                m_elAddinfo = QSharedPointer<CDDDbADDINFO>::create();
                if (m_elAddinfo) {
                    m_elAddinfo->load(childElement);
                }
            } else if (elementName == "TEXT") {
                m_elText = QSharedPointer<CDDDbTEXT>::create();
                if (m_elText) {
                    m_elText->load(childElement);
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
