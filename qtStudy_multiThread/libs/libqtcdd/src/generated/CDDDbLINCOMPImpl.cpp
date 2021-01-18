#include "CDDDbCOMP.h"
#include "CDDDbCVALUETYPE.h"
#include "CDDDbEXCL.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"

#include "CDDDbLINCOMPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbLINCOMPImpl::CDDDbLINCOMPImpl()
{
}

CDDDbLINCOMPImpl::~CDDDbLINCOMPImpl()
{
}

void CDDDbLINCOMPImpl::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "COMP") {
                m_elComp = QSharedPointer<CDDDbCOMP>::create();
                if (m_elComp) {
                    m_elComp->load(childElement);
                }
            } else if (elementName == "CVALUETYPE") {
                m_elCvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
                if (m_elCvaluetype) {
                    m_elCvaluetype->load(childElement);
                }
            } else if (elementName == "EXCL") {
                auto o = QSharedPointer<CDDDbEXCL>::create();
                if (o) {
                    o->load(childElement);
                    m_elExcls.append(o);
                }
            } else if (elementName == "NAME") {
                m_elName = QSharedPointer<CDDDbNAME>::create();
                if (m_elName) {
                    m_elName->load(childElement);
                }
            } else if (elementName == "PVALUETYPE") {
                m_elPvaluetype = QSharedPointer<CDDDbPVALUETYPE>::create();
                if (m_elPvaluetype) {
                    m_elPvaluetype->load(childElement);
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
