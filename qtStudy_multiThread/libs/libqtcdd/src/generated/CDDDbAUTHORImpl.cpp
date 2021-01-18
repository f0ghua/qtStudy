#include "CDDDbCOMPANY.h"
#include "CDDDbFIRSTNAME.h"
#include "CDDDbLASTNAME.h"
#include "CDDDbSHORTNAME.h"

#include "CDDDbAUTHORImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAUTHORImpl::CDDDbAUTHORImpl()
{
}

CDDDbAUTHORImpl::~CDDDbAUTHORImpl()
{
}

void CDDDbAUTHORImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_obs = element.attribute("obs");
    m_responsible = element.attribute("responsible");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "COMPANY") {
                m_elCompany = QSharedPointer<CDDDbCOMPANY>::create();
                if (m_elCompany) {
                    m_elCompany->load(childElement);
                }
            } else if (elementName == "FIRSTNAME") {
                m_elFirstname = QSharedPointer<CDDDbFIRSTNAME>::create();
                if (m_elFirstname) {
                    m_elFirstname->load(childElement);
                }
            } else if (elementName == "LASTNAME") {
                m_elLastname = QSharedPointer<CDDDbLASTNAME>::create();
                if (m_elLastname) {
                    m_elLastname->load(childElement);
                }
            } else if (elementName == "SHORTNAME") {
                m_elShortname = QSharedPointer<CDDDbSHORTNAME>::create();
                if (m_elShortname) {
                    m_elShortname->load(childElement);
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
