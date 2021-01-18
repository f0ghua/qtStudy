#include "CDDDbCVALUETYPE.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbEXCL.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"

#include "CDDDbIDENTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbIDENTImpl::CDDDbIDENTImpl()
{
}

CDDDbIDENTImpl::~CDDDbIDENTImpl()
{
}

void CDDDbIDENTImpl::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");
    m_xauth = element.attribute("xauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CVALUETYPE") {
                m_elCvaluetype = QSharedPointer<CDDDbCVALUETYPE>::create();
                if (m_elCvaluetype) {
                    m_elCvaluetype->load(childElement);
                }
            } else if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "ENUM") {
                auto o = QSharedPointer<CDDDbENUM>::create();
                if (o) {
                    o->load(childElement);
                    m_elEnums.append(o);
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
