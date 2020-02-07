#include "HOCompuMethods.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCompuMethods::HOCompuMethods()
    : HONameDetails()
{
}

void HOCompuMethods::load(const QDomElement &element)
{
    HONameDetails::load(element);

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCompuMethods::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:CATEGORY") {
            QString typeStr = element.text();
            FibexTypes::EnumParser<FibexTypes::HOCompuCategorySt> ep;
            FibexTypes::HOCompuCategorySt type;
            bool isOk = ep.str2Enum(typeStr, type);
            if (isOk) {
                m_compuCategory = type;
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "HOCompuMethods::load, m_compuCategory =" << typeStr << (int)m_compuCategory;
#endif
            }
        } else if (childElement.tagName() == "ho:UNIT-REF") {
            m_unitRef = childElement.attribute("ID-REF");
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOCompuMethods::load, m_unitRef =" << m_unitRef;
#endif
        } else if (childElement.tagName() == "ho:PHYS-CONSTRS") {
            m_physConstrs.load(childElement);
        } else if (childElement.tagName() == "ho:INTERNAL-CONSTRS") {
            m_internalConstrs.load(childElement);
        } else if (childElement.tagName() == "ho:COMPU-INTERNAL-TO-PHYS") {
            m_compuInternalToPhys.load(childElement);
        } else if (childElement.tagName() == "ho:DESC") {

        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
