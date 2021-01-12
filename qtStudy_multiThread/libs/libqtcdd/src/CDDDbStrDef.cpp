#include "CDDLog.h"
#include "CDDDbStrDef.h"
#include "CDDDbTuvedType.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbStrDef::CDDDbStrDef()
    : CDDDbNamedElementType()
    , CDDDbAttrCatRefType()
{
}

CDDDbStrDef::~CDDDbStrDef()
{

}

void CDDDbStrDef::load(const QDomElement &element)
{
    CDDDbNamedElementType::load(element);
    CDDDbAttrCatRefType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbAttrCats::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "STRING") {
            m_string.load(childElement);
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
