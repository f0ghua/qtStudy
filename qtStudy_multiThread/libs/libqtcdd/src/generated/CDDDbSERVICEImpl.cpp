#include "CDDDbENUM.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHORTCUTNAME.h"
#include "CDDDbSHORTCUTQUAL.h"

#include "CDDDbSERVICEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSERVICEImpl::CDDDbSERVICEImpl()
{
}

CDDDbSERVICEImpl::~CDDDbSERVICEImpl()
{
}

void CDDDbSERVICEImpl::load(const QDomElement &element)
{
    m_func = element.attribute("func");
    m_id = element.attribute("id");
    m_mayBeExec = element.attribute("mayBeExec");
    m_oid = element.attribute("oid");
    m_phys = element.attribute("phys");
    m_req = element.attribute("req");
    m_respOnFunc = element.attribute("respOnFunc");
    m_respOnPhys = element.attribute("respOnPhys");
    m_temploid = element.attribute("temploid");
    m_tmplref = element.attribute("tmplref");
    m_trans = element.attribute("trans");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ENUM") {
                auto o = QSharedPointer<CDDDbENUM>::create();
                if (o) {
                    o->load(childElement);
                    m_elEnums.append(o);
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
            } else if (elementName == "SHORTCUTNAME") {
                m_elShortcutname = QSharedPointer<CDDDbSHORTCUTNAME>::create();
                if (m_elShortcutname) {
                    m_elShortcutname->load(childElement);
                }
            } else if (elementName == "SHORTCUTQUAL") {
                m_elShortcutqual = QSharedPointer<CDDDbSHORTCUTQUAL>::create();
                if (m_elShortcutqual) {
                    m_elShortcutqual->load(childElement);
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
