#include "CDDLog.h"
#include "CDDDbAttrCat.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAttrCat::CDDDbAttrCat()
    : CDDDbOidElementType()
{
}

CDDDbAttrCat::~CDDDbAttrCat()
{

}

void CDDDbAttrCat::load(const QDomElement &element)
{
    CDDDbOidElementType::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbAttrCat::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "NAME") {

        } else if (childElement.tagName() == "DESC") {

        } else if (childElement.tagName() == "QUAL") {

        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
