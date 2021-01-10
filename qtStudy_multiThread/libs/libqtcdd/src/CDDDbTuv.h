#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element TUV
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbTuv
{
public:
    CDDDbTuv();
    ~CDDDbTuv();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /** element ELEMENTS */
    QMap<QString, QString> m_values;

};

} // namespace cdd
} // namespace vector
