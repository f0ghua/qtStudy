#include "CDDDbDATAOBJ.h"
#include "CDDDbGAPDATAOBJ.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTRUCTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRUCTImpl::CDDDbSTRUCTImpl()
{
}

CDDDbSTRUCTImpl::~CDDDbSTRUCTImpl()
{
}

void CDDDbSTRUCTImpl::load(const QDomElement &element)
{
    m_dtref = element.attribute("dtref");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DATAOBJ") {
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
