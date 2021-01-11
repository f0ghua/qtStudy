#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element which defined with attribute id
 *
 * id element
 */
class VECTOR_CDD_API CDDDbIdElementType
{
public:
    CDDDbIdElementType();
    ~CDDDbIdElementType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @must attribute ID */
    QString m_id;

};

} // namespace cdd
} // namespace vector
