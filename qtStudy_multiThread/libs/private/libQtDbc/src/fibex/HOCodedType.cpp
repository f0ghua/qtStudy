#include "HOCodedType.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

HOCodedType::HOCodedType(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
{
}

void HOCodedType::load(const QDomElement &element)
{
    m_baseDataType = element.attribute("ho:BASE-DATA-TYPE");
    m_category = element.attribute("CATEGORY");
    m_encoding = element.attribute("ENCODING");

#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "HOCodedType::load m_baseDataType" << m_baseDataType;
    QLOG_DEBUG() << "HOCodedType::load m_category" << m_category;
    QLOG_DEBUG() << "HOCodedType::load m_encoding" << m_encoding;
#endif

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "HOCodedType::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ho:BIT-LENGTH") {
            m_bitLength = childElement.text().toUInt();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOCodedType::load m_bitLength" << m_bitLength;
#endif
        } else if (childElement.tagName() == "ho:MIN-LENGTH") {
            m_minLength = childElement.text().toUInt();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOCodedType::load m_minLength" << m_minLength;
#endif
        } else if (childElement.tagName() == "ho:MAX-LENGTH") {
            m_maxLength = childElement.text().toUInt();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << "HOCodedType::load m_maxLength" << m_maxLength;
#endif
        }

        child = child.nextSibling();
    }
}

} // FIBEX
} // ASAM
