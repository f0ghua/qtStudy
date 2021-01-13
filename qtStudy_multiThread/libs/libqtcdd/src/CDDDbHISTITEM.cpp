#include "CDDDbLABEL.h"
#include "CDDDbMOD.h"
#include "CDDDbREASON.h"

#include "CDDDbHISTITEM.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbHISTITEM::CDDDbHISTITEM()
{
}

CDDDbHISTITEM::~CDDDbHISTITEM()
{
}

void CDDDbHISTITEM::load(const QDomElement &element)
{
    m_authorref = element.attribute("authorref");
    m_dt = element.attribute("dt");
    m_stid = element.attribute("stid");
    m_tool = element.attribute("tool");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "LABEL") {
            m_label = QSharedPointer<CDDDbLABEL>::create();
            if (m_label) {
                m_label->load(childElement);
            }
        } else if (elementName == "MOD") {
            m_mod = QSharedPointer<CDDDbMOD>::create();
            if (m_mod) {
                m_mod->load(childElement);
            }
        } else if (elementName == "REASON") {
            m_reason = QSharedPointer<CDDDbREASON>::create();
            if (m_reason) {
                m_reason->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
