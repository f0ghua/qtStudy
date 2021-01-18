#include "CDDDbDCLSRVTMPL.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHPROXY.h"
#include "CDDDbSHSTATIC.h"

#include "CDDDbDCLTMPLImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDCLTMPLImpl::CDDDbDCLTMPLImpl()
{
}

CDDDbDCLTMPLImpl::~CDDDbDCLTMPLImpl()
{
}

void CDDDbDCLTMPLImpl::load(const QDomElement &element)
{
    m_cls = element.attribute("cls");
    m_id = element.attribute("id");
    m_isRelevantForReq = element.attribute("isRelevantForReq");
    m_oid = element.attribute("oid");
    m_single = element.attribute("single");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DCLSRVTMPL") {
                auto o = QSharedPointer<CDDDbDCLSRVTMPL>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDclsrvtmpls.insert(o->m_id, o);
                    }
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
            } else if (elementName == "SHPROXY") {
                auto o = QSharedPointer<CDDDbSHPROXY>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elShproxys.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "SHSTATIC") {
                m_elShstatic = QSharedPointer<CDDDbSHSTATIC>::create();
                if (m_elShstatic) {
                    m_elShstatic->load(childElement);
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
