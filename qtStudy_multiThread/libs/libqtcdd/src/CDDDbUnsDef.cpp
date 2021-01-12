#include "CDDLog.h"
#include "CDDDbUnsDef.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUnsDef::CDDDbUnsDef()
    : CDDDbNamedElementType()
    , CDDDbAttrCatRefType()
{
}

CDDDbUnsDef::~CDDDbUnsDef()
{

}

void CDDDbUnsDef::load(const QDomElement &element)
{
    CDDDbNamedElementType::load(element);
    CDDDbAttrCatRefType::load(element);

    m_value = element.attribute("v").toUInt();
    QString typeStr = element.attribute("df");
    EnumParser<CDDUnsignedDataFormat> ep;
    CDDUnsignedDataFormat e;
    bool isOk = ep.str2Enum(typeStr, e);
    if (isOk) {
        m_df = e;
//#ifndef F_NO_DEBUG
//        QLOG_TRACE() << "CDDDbUnsDef::load, m_df =" << typeStr << static_cast<int>(m_df);
//#endif
    }
}

} // namespace cdd
} // namespace vector
