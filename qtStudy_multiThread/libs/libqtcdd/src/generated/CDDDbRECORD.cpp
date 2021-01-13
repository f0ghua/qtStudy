#include "CDDDbENUMRECORDITEM.h"
#include "CDDDbTEXT.h"
#include "CDDDbTRRECORDITEM.h"
#include "CDDDbUNSRECORDITEM.h"

#include "CDDDbRECORD.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORD::CDDDbRECORD()
{
}

CDDDbRECORD::~CDDDbRECORD()
{
}

void CDDDbRECORD::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_v = element.attribute("v");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ENUMRECORDITEM") {
            auto o = QSharedPointer<CDDDbENUMRECORDITEM>::create();
            if (o) {
                o->load(childElement);
                m_enumrecorditems.append(o);
            }
        } else if (elementName == "TEXT") {
            m_text = QSharedPointer<CDDDbTEXT>::create();
            if (m_text) {
                m_text->load(childElement);
            }
        } else if (elementName == "TRRECORDITEM") {
            auto o = QSharedPointer<CDDDbTRRECORDITEM>::create();
            if (o) {
                o->load(childElement);
                m_trrecorditems.append(o);
            }
        } else if (elementName == "UNSRECORDITEM") {
            auto o = QSharedPointer<CDDDbUNSRECORDITEM>::create();
            if (o) {
                o->load(childElement);
                m_unsrecorditems.append(o);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
