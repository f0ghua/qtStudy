#include "CDDDbLABEL.h"
#include "CDDDbMOD.h"
#include "CDDDbREASON.h"

#include "CDDDbHISTITEMImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbHISTITEMImpl::CDDDbHISTITEMImpl()
{
}

CDDDbHISTITEMImpl::~CDDDbHISTITEMImpl()
{
}

void CDDDbHISTITEMImpl::load(const QDomElement &element)
{
    m_authorref = element.attribute("authorref");
    m_dt = element.attribute("dt");
    m_stid = element.attribute("stid");
    m_tool = element.attribute("tool");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "LABEL") {
                m_elLabel = QSharedPointer<CDDDbLABEL>::create();
                if (m_elLabel) {
                    m_elLabel->load(childElement);
                }
            } else if (elementName == "MOD") {
                m_elMod = QSharedPointer<CDDDbMOD>::create();
                if (m_elMod) {
                    m_elMod->load(childElement);
                }
            } else if (elementName == "REASON") {
                m_elReason = QSharedPointer<CDDDbREASON>::create();
                if (m_elReason) {
                    m_elReason->load(childElement);
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
