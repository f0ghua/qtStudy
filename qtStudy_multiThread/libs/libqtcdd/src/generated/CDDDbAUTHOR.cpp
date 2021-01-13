#include "CDDDbCOMPANY.h"
#include "CDDDbFIRSTNAME.h"
#include "CDDDbLASTNAME.h"
#include "CDDDbSHORTNAME.h"

#include "CDDDbAUTHOR.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAUTHOR::CDDDbAUTHOR()
{
}

CDDDbAUTHOR::~CDDDbAUTHOR()
{
}

void CDDDbAUTHOR::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_obs = element.attribute("obs");
    m_responsible = element.attribute("responsible");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "COMPANY") {
            m_company = QSharedPointer<CDDDbCOMPANY>::create();
            if (m_company) {
                m_company->load(childElement);
            }
        } else if (elementName == "FIRSTNAME") {
            m_firstname = QSharedPointer<CDDDbFIRSTNAME>::create();
            if (m_firstname) {
                m_firstname->load(childElement);
            }
        } else if (elementName == "LASTNAME") {
            m_lastname = QSharedPointer<CDDDbLASTNAME>::create();
            if (m_lastname) {
                m_lastname->load(childElement);
            }
        } else if (elementName == "SHORTNAME") {
            m_shortname = QSharedPointer<CDDDbSHORTNAME>::create();
            if (m_shortname) {
                m_shortname->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
