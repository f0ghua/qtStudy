#include "CDDDbPROTOCOLSERVICE.h"

#include "CDDDbPROTOCOLSERVICES.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICES::CDDDbPROTOCOLSERVICES()
{
}

CDDDbPROTOCOLSERVICES::~CDDDbPROTOCOLSERVICES()
{
}

void CDDDbPROTOCOLSERVICES::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "PROTOCOLSERVICE") {
            auto o = QSharedPointer<CDDDbPROTOCOLSERVICE>::create();
            if (o) {
                o->load(childElement);
                if (!o->m_id.isEmpty()) {
                    m_protocolservices.insert(o->m_id, o);
                }
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
