#include "CDDLog.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbTuv::CDDDbTuv()
{
}

CDDDbTuv::~CDDDbTuv()
{

}

bool CDDDbTuv::load(const QDomElement &element)
{
    bool ret = true;

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDbTuv::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "TUV") {
            QString lang = element.attribute("xml:lang");
            QString value = childElement.text().simplified();
            if (!lang.isEmpty() && !value.isEmpty()) {
                m_values.insert(lang, value);
            }
        }

        child = child.nextSibling();
    }

    return ret;
}

} // namespace cdd
} // namespace vector
