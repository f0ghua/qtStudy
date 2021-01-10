#include "CDDLog.h"
#include "CDDDbECUDoc.h"
#include "CDDDatabase.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDatabase::CDDDatabase()
{
}

CDDDatabase::~CDDDatabase()
{

}

bool CDDDatabase::load(const QDomElement &element)
{
    bool ret = true;

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDatabase::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ECUDOC") {
            m_ecudoc = QSharedPointer<CDDDbECUDoc>::create();
            m_ecudoc->load(childElement);
        }

        child = child.nextSibling();
    }

    return ret;
}

} // namespace cdd
} // namespace vector
