#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRING.h"

#include "CDDDbSTRDEF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRDEF::CDDDbSTRDEF()
{
}

CDDDbSTRDEF::~CDDDbSTRDEF()
{
}

void CDDDbSTRDEF::load(const QDomElement &element)
{
    m_attrcatref = element.attribute("attrcatref");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DESC") {
            m_desc = QSharedPointer<CDDDbDESC>::create();
            if (m_desc) {
                m_desc->load(childElement);
            }
        } else if (elementName == "NAME") {
            m_name = QSharedPointer<CDDDbNAME>::create();
            if (m_name) {
                m_name->load(childElement);
            }
        } else if (elementName == "QUAL") {
            m_qual = QSharedPointer<CDDDbQUAL>::create();
            if (m_qual) {
                m_qual->load(childElement);
            }
        } else if (elementName == "STRING") {
            m_string = QSharedPointer<CDDDbSTRING>::create();
            if (m_string) {
                m_string->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
