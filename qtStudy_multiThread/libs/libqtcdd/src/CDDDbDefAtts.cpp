#include "CDDDbECUAtts.h"
#include "CDDLog.h"

#include "CDDDbDefAtts.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDefAtts::CDDDbDefAtts()
{
}

CDDDbDefAtts::~CDDDbDefAtts()
{

}

void CDDDbDefAtts::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbDefAtts::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "DATAOBJATTS") {

        } else if (childElement.tagName() == "DATATYPEATTS") {

        } else if (childElement.tagName() == "DIAGCLASSATTS") {

            QDomNode subChild = child.firstChild();
            while (!subChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "CDDDbDefAtts::load ENUMDEFS" << childElement.tagName();
#endif
                if (subChild.toElement().tagName() == "ENUMDEF") {
//                    auto enumdef = QSharedPointer<CDDDbTuv>::create();
//                    enumdef->load(subChild.toElement());
//                    m_enumdefs[enumdef->m_id] = enumdef;
                }
                subChild = subChild.nextSibling();
            }

        } else if (childElement.tagName() == "DIAGINSTATTS") {

        } else if (childElement.tagName() == "ECUATTS") {
            m_ecuatts = QSharedPointer<CDDDbECUAtts>::create();
            if (m_ecuatts) {
                m_ecuatts->load(childElement);
            }
        } else if (childElement.tagName() == "JOBATTS") {

        } else if (childElement.tagName() == "JOBCNRATTS") {

        } else if (childElement.tagName() == "RECORDATTS") {

        } else if (childElement.tagName() == "SERVICEATTS") {

        } else if (childElement.tagName() == "VARATTS") {

        } else if (childElement.tagName() == "STATEGROUPATTS") {

        } else if (childElement.tagName() == "DCLTMPLATTS") {

        } else if (childElement.tagName() == "DCLSRVTMPLATTS") {

        } else if (childElement.tagName() == "SHPROXYATTS") {

        } else if (childElement.tagName() == "DIDATTS") {

        }

        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector
