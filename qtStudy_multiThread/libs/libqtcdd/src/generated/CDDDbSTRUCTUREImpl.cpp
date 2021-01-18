#include "CDDDbDATAOBJ.h"

#include "CDDDbSTRUCTUREImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTRUCTUREImpl::CDDDbSTRUCTUREImpl()
{
}

CDDDbSTRUCTUREImpl::~CDDDbSTRUCTUREImpl()
{
}

void CDDDbSTRUCTUREImpl::load(const QDomElement &element)
{
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
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
