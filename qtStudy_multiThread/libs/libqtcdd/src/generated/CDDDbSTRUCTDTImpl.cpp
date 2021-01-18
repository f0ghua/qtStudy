#include "CDDDbCVALUETYPE.h"
#include "CDDDbDATAOBJ.h"
#include "CDDDbGAPDATAOBJ.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCT.h"

#include "CDDDbSTRUCTDTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRUCTDTImpl::CDDDbSTRUCTDTImpl()
{
}

CDDDbSTRUCTDTImpl::~CDDDbSTRUCTDTImpl()
{
}

void CDDDbSTRUCTDTImpl::load(const QDomElement &element)
{
    m_bm = element.attribute("bm");
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_showContOnly = element.attribute("showContOnly");
    m_temploid = element.attribute("temploid");

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
            } else if (elementName == "DATAOBJ") {
                auto o = QSharedPointer<CDDDbDATAOBJ>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDataobjs.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "GAPDATAOBJ") {
                auto o = QSharedPointer<CDDDbGAPDATAOBJ>::create();
                if (o) {
                    o->load(childElement);
                    m_elGapdataobjs.append(o);
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
            } else if (elementName == "STRUCT") {
                auto o = QSharedPointer<CDDDbSTRUCT>::create();
                if (o) {
                    o->load(childElement);
                    m_elStructs.append(o);
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
