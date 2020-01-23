#include "FXNamedElementType.h"
#include "LogDb.h"

#include <QDomElement>

namespace ASAM {
namespace FIBEX {

FXNamedElementType::FXNamedElementType()
    : HONameDetails()
{
}

void FXNamedElementType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "FXNamedElementType::load, m_id =" << m_id;
#endif

    HONameDetails::load(element);
}

}
}

