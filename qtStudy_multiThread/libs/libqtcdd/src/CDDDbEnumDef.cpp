#include "CDDLog.h"
#include "CDDDbEtag.h"
#include "CDDDbEnumDef.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEnumDef::CDDDbEnumDef()
    : CDDDbNamedElementType()
    , CDDDbAttrCatRefType()
{
}

CDDDbEnumDef::~CDDDbEnumDef()
{

}

void CDDDbEnumDef::load(const QDomElement &element)
{
    CDDDbNamedElementType::load(element);
    CDDDbAttrCatRefType::load(element);

    m_value = element.attribute("v").toUInt();
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbEnumDef::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ETAG") {
            CDDDbEtag etag;
            etag.load(childElement);

            m_etags.insert(etag.value(), etag.text());
        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
