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
class VECTOR_CDD_API CDDDbECUDoc
{
public:
    CDDDbECUDoc();
    ~CDDDbECUDoc();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /** element ELEMENTS */


};

} // namespace cdd
} // namespace vector
