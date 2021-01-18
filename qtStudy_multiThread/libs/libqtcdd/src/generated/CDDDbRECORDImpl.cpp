#include "CDDDbCSTR.h"
#include "CDDDbENUM.h"
#include "CDDDbENUMRECORDITEM.h"
#include "CDDDbTEXT.h"
#include "CDDDbTRRECORDITEM.h"
#include "CDDDbUNS.h"
#include "CDDDbUNSRECORDITEM.h"

#include "CDDDbRECORDImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDImpl::CDDDbRECORDImpl()
{
}

CDDDbRECORDImpl::~CDDDbRECORDImpl()
{
}

void CDDDbRECORDImpl::load(const QDomElement &element)
{
    m_id = element.attribute("id");
    m_oid = element.attribute("oid");
    m_v = element.attribute("v");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "CSTR") {
                auto o = QSharedPointer<CDDDbCSTR>::create();
                if (o) {
                    o->load(childElement);
                    m_elCstrs.append(o);
                }
            } else if (elementName == "ENUM") {
                auto o = QSharedPointer<CDDDbENUM>::create();
                if (o) {
                    o->load(childElement);
                    m_elEnums.append(o);
                }
            } else if (elementName == "ENUMRECORDITEM") {
                auto o = QSharedPointer<CDDDbENUMRECORDITEM>::create();
                if (o) {
                    o->load(childElement);
                    m_elEnumrecorditems.append(o);
                }
            } else if (elementName == "TEXT") {
                m_elText = QSharedPointer<CDDDbTEXT>::create();
                if (m_elText) {
                    m_elText->load(childElement);
                }
            } else if (elementName == "TRRECORDITEM") {
                auto o = QSharedPointer<CDDDbTRRECORDITEM>::create();
                if (o) {
                    o->load(childElement);
                    m_elTrrecorditems.append(o);
                }
            } else if (elementName == "UNS") {
                auto o = QSharedPointer<CDDDbUNS>::create();
                if (o) {
                    o->load(childElement);
                    m_elUnss.append(o);
                }
            } else if (elementName == "UNSRECORDITEM") {
                auto o = QSharedPointer<CDDDbUNSRECORDITEM>::create();
                if (o) {
                    o->load(childElement);
                    m_elUnsrecorditems.append(o);
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
