#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDTPOOL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbRECORDDTPOOL::CDDDbRECORDDTPOOL()
{
}

CDDDbRECORDDTPOOL::~CDDDbRECORDDTPOOL()
{
}

void CDDDbRECORDDTPOOL::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "RECORDDT") {
            m_recorddt = QSharedPointer<CDDDbRECORDDT>::create();
            if (m_recorddt) {
                m_recorddt->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
