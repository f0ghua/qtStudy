#include "FXFibex.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXFibex::FXFibex()
/*
    : project()
    , protocols()
    , elements()
    , processingInformation()
    , requirements()
    , version()
*/
{
}

bool FXFibex::load(const QDomElement &element)
{
    bool ret = true;

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXFibex::load" << child.toElement().tagName();
#endif
        if (child.toElement().tagName() == "fx:PROJECT") {

        } else if (child.toElement().tagName() == "fx:PROTOCOLS") {

        } else if (child.toElement().tagName() == "fx:ELEMENTS") {
            m_elements.load(child.toElement());
        } else if (child.toElement().tagName() == "fx:PROCESSING-INFORMATION") {

        } else if (child.toElement().tagName() == "fx:REQUIREMENTS") {

        }

        child = child.nextSibling();
    }

    return ret;
}

}
}
