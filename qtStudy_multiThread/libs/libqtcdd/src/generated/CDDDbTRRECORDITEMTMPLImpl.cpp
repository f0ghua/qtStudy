#include "CDDDbCHOICE.h"
#include "CDDDbDEFAULT.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbTRRECORDITEMTMPLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTRRECORDITEMTMPLImpl::CDDDbTRRECORDITEMTMPLImpl()
{
}

CDDDbTRRECORDITEMTMPLImpl::~CDDDbTRRECORDITEMTMPLImpl()
{
}

void CDDDbTRRECORDITEMTMPLImpl::load(const QDomElement &element)
{
    m_conv = element.attribute("conv");
    m_id = element.attribute("id");
    m_mayBeDup = element.attribute("mayBeDup");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CHOICE") {
                auto o = QSharedPointer<CDDDbCHOICE>::create();
                if (o) {
                    o->load(childElement);
                    m_elChoices.append(o);
                }
            } else if (elementName == "DEFAULT") {
                m_elDefault = QSharedPointer<CDDDbDEFAULT>::create();
                if (m_elDefault) {
                    m_elDefault->load(childElement);
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
