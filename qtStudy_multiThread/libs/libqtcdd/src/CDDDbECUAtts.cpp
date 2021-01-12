#include "CDDDbCstrDef.h"
#include "CDDDbEnumDef.h"
#include "CDDDbStrDef.h"
#include "CDDDbUnsDef.h"
#include "CDDLog.h"
#include "CDDDbECUAtts.h"


#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECUAtts::CDDDbECUAtts()
{
}

CDDDbECUAtts::~CDDDbECUAtts()
{

}

void CDDDbECUAtts::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbECUAtts::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ENUMDEF") {
            auto def = QSharedPointer<CDDDbEnumDef>::create();
            if (def) {
                def->load(childElement);
                if (!def->id().isEmpty()) {
                    m_enumdefs.insert(def->id(), def);
#ifndef F_NO_DEBUG
                    QLOG_TRACE() << "CDDDbECUAtts::ENUMDEF insert" << def->name() << def->m_etags;
#endif
                }
            }
        } else if (childElement.tagName() == "UNSDEF") {
            auto def = QSharedPointer<CDDDbUnsDef>::create();
            if (def) {
                def->load(childElement);
                if (!def->id().isEmpty()) {
                    m_unsdefs.insert(def->id(), def);
#ifndef F_NO_DEBUG
                    QLOG_TRACE() << "CDDDbECUAtts::UNSDEF insert" << def->name() << def->value() << def->dataFormat();
#endif
                }
            }
        } else if (childElement.tagName() == "CSTRDEF") {
            auto def = QSharedPointer<CDDDbCstrDef>::create();
            if (def) {
                def->load(childElement);
                if (!def->id().isEmpty()) {
                    m_cstrdefs.insert(def->id(), def);
#ifndef F_NO_DEBUG
                    QLOG_TRACE() << "CDDDbECUAtts::CSTRDEF insert" << def->name();
#endif
                }
            }
        } else if (childElement.tagName() == "STRDEF") {
            auto def = QSharedPointer<CDDDbStrDef>::create();
            if (def) {
                def->load(childElement);
                if (!def->id().isEmpty()) {
                    m_strdefs.insert(def->id(), def);
#ifndef F_NO_DEBUG
                    QLOG_TRACE() << "CDDDbECUAtts::STRDEF insert" << def->name() << def->string();
#endif
                }
            }
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
