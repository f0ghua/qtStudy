#include "FXFibex.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXFibex::FXFibex(QObject *parent)
    : QObject(parent)
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
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXFibex::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:PROCESSING-INFORMATION") {
            if (!m_processingInformation) {
                m_processingInformation = new FXProcessingInformation(this, this);
                m_processingInformation->load(childElement);
            }
        } else if (childElement.tagName() == "fx:ELEMENTS") {
            if (!m_elements) {
                m_elements = new FXElements(this, this);
                m_elements->load(child.toElement());
            }
        } else if (childElement.tagName() == "fx:PROJECT") {

        } else if (childElement.tagName() == "fx:PROTOCOLS") {

        } else if (childElement.tagName() == "fx:REQUIREMENTS") {

        }

        child = child.nextSibling();
    }

    return ret;
}

}
}
