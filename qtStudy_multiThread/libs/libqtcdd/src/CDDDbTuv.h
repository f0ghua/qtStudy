#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element TUV
 *
 * translation unit variant
 */
class VECTOR_CDD_API CDDDbTuv
{
public:
    static QString ATTR_T_LANG;
    static QString ATTR_V_ENUS;

    CDDDbTuv();
    ~CDDDbTuv();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString getValue() const
    {
        return m_value;
    }

    /** element ELEMENTS */
    QString m_lang;
    QString m_value;

};

} // namespace cdd
} // namespace vector
