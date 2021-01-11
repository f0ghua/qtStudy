#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element ECUDOC
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbECU
{
public:
    CDDDbECU();
    ~CDDDbECU();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ELEMENTS */


};

} // namespace cdd
} // namespace vector
