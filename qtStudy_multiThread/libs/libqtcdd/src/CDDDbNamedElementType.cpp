#include "CDDDbDesc.h"
#include "CDDDbName.h"
#include "CDDDbQual.h"
#include "CDDLog.h"
#include "CDDDbNamedElementType.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNamedElementType::CDDDbNamedElementType()
    : CDDDbOidElementType()
{
}

CDDDbNamedElementType::~CDDDbNamedElementType()
{
}

void CDDDbNamedElementType::load(const QDomElement &element)
{
    CDDDbOidElementType::load(element);

    m_oid = element.attribute("oid");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbNamedElementType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "NAME") {
            m_name = QSharedPointer<CDDDbName>::create();
            m_name->load(childElement);
        } else if (childElement.tagName() == "DESC") {
            m_desc = QSharedPointer<CDDDbDesc>::create();
            m_desc->load(childElement);
        } else if (childElement.tagName() == "QUAL") {
            m_qual = QSharedPointer<CDDDbQual>::create();
            m_qual->load(childElement);
        }

        child = child.nextSibling();
    }
}

QString CDDDbNamedElementType::name() const
{
    return m_name?m_name->getValue():QString();
}

QString CDDDbNamedElementType::desc() const
{
    return m_desc?m_desc->getValue():QString();
}

QString CDDDbNamedElementType::qual() const
{
    return m_qual?m_qual->getValue():QString();
}


} // namespace cdd
} // namespace vector
