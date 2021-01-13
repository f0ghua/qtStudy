#include "CDDDbDCLSRVTMPL.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHPROXY.h"
#include "CDDDbSHSTATIC.h"

#include "CDDDbDCLTMPL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDCLTMPL::CDDDbDCLTMPL()
{
}

CDDDbDCLTMPL::~CDDDbDCLTMPL()
{
}

void CDDDbDCLTMPL::load(const QDomElement &element)
{
    m_cls = element.attribute("cls");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_single = element.attribute("single");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DCLSRVTMPL") {
            auto o = QSharedPointer<CDDDbDCLSRVTMPL>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_dclsrvtmpls.insert(o->m_id, o);
                }
            }
        } else if (elementName == "DESC") {
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
        } else if (elementName == "SHPROXY") {
            auto o = QSharedPointer<CDDDbSHPROXY>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_shproxys.insert(o->m_id, o);
                }
            }
        } else if (elementName == "SHSTATIC") {
            m_shstatic = QSharedPointer<CDDDbSHSTATIC>::create();
            if (m_shstatic) {
                m_shstatic->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
