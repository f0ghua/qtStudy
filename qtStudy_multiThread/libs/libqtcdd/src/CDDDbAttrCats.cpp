#include "CDDLog.h"
#include "CDDDbAttrCat.h"
#include "CDDDbAttrCats.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAttrCats::CDDDbAttrCats()
{
}

CDDDbAttrCats::~CDDDbAttrCats()
{

}

void CDDDbAttrCats::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
            QLOG_TRACE() << "CDDDbAttrCats::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ATTRCAT") {
            auto attrcat = QSharedPointer<CDDDbAttrCat>::create();
            attrcat->load(childElement);
            if (!attrcat->m_id.isEmpty()) {
                m_attrcats[attrcat->m_id] = attrcat;
            }
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
