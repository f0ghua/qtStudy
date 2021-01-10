#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element CANDELA
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbCANdela
{
public:
    CDDDbCANdela();
    ~CDDDbCANdela();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /** element ELEMENTS */


};

} // namespace cdd
} // namespace vector
