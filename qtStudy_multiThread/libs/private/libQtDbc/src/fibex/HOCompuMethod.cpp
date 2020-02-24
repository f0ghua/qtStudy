#include "HOCompuMethod.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompuMethod::HOCompuMethod(FXFibex *fibex, QObject *parent)
    : HONameDetails()
    , QObject(parent)
    , m_fibex(fibex)
{
}

void HOCompuMethod::load(const QDomElement &element)
{
    HONameDetails::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompuMethod::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:CATEGORY") {
            QString typeStr = childElement.text();
            FibexTypes::EnumParser<FibexTypes::HOCompuCategorySt> ep;
            FibexTypes::HOCompuCategorySt type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_compuCategory = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "HOCompuMethod::load, m_compuCategory =" << typeStr << (int)m_compuCategory;
#endif
            }
        } else if (childElement.tagName() == "ho:UNIT-REF") {
            m_unitRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOCompuMethod::load, m_unitRef =" << m_unitRef;
#endif
        } else if (childElement.tagName() == "ho:PHYS-CONSTRS") {
            m_physConstrs.load(childElement);
        } else if (childElement.tagName() == "ho:INTERNAL-CONSTRS") {
            m_internalConstrs.load(childElement);
        } else if (childElement.tagName() == "ho:COMPU-INTERNAL-TO-PHYS") {
            if (!m_compuInternalToPhys) {
                m_compuInternalToPhys = new HOCompInternalToPhys(m_fibex, this);
                m_compuInternalToPhys->load(childElement);
            }
        } else if (childElement.tagName() == "ho:DESC") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
