#include "HOCompuMethods.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompuMethods::HOCompuMethods()
{
}

void HOCompuMethods::load(const QDomElement &element)
{
    m_compuMethodList.clear();

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompuMethods::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:COMPU-METHOD") {
            HOCompuMethod cm;
            cm.load(childElement);
            m_compuMethodList.append(cm);
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
