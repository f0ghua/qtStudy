#include "CDDDbCOMMONSTRING.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbCSTRDEFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCSTRDEFImpl::CDDDbCSTRDEFImpl()
{
}

CDDDbCSTRDEFImpl::~CDDDbCSTRDEFImpl()
{
}

void CDDDbCSTRDEFImpl::load(const QDomElement &element)
{
    m_attrcatref = element.attribute("attrcatref");
    m_id = element.attribute("id");
    m_listable = element.attribute("listable");
    m_mayBeReported = element.attribute("mayBeReported");
    m_oid = element.attribute("oid");
    m_restr = element.attribute("restr");
    m_temploid = element.attribute("temploid");
    m_usage = element.attribute("usage");
    m_xauth = element.attribute("xauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "COMMONSTRING") {
                m_elCommonstring = QSharedPointer<CDDDbCOMMONSTRING>::create();
                if (m_elCommonstring) {
                    m_elCommonstring->load(childElement);
                }
            } else if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "QUAL") {
                m_elQual = QSharedPointer<CDDDbQUAL>::create();
                if (m_elQual) {
                    m_elQual->load(childElement);
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
