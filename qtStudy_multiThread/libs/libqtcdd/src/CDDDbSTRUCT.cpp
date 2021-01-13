#include "CDDDbDATAOBJ.h"
#include "CDDDbGAPDATAOBJ.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTRUCT.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRUCT::CDDDbSTRUCT()
{
}

CDDDbSTRUCT::~CDDDbSTRUCT()
{
}

void CDDDbSTRUCT::load(const QDomElement &element)
{
    m_dtref = element.attribute("dtref");
    m_oid = element.attribute("oid");
    m_spec = element.attribute("spec");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DATAOBJ") {
            auto o = QSharedPointer<CDDDbDATAOBJ>::create();
            if (o) {
                o->load(childElement);
                m_dataobjs.append(o);
            }
        } else if (elementName == "GAPDATAOBJ") {
            auto o = QSharedPointer<CDDDbGAPDATAOBJ>::create();
            if (o) {
                o->load(childElement);
                m_gapdataobjs.append(o);
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
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
