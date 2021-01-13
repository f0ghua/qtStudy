#include "CDDDbAUTHOR.h"

#include "CDDDbAUTHORS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAUTHORS::CDDDbAUTHORS()
{
}

CDDDbAUTHORS::~CDDDbAUTHORS()
{
}

void CDDDbAUTHORS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "AUTHOR") {
            m_author = QSharedPointer<CDDDbAUTHOR>::create();
            if (m_author) {
                m_author->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
