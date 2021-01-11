#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbOidElementType.h"

namespace vector {
namespace cdd {

/**
 * @brief element ATTRCAT
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbAttrCat : public CDDDbOidElementType
{
public:
    CDDDbAttrCat();
    ~CDDDbAttrCat();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ELEMENTS */


};

} // namespace cdd
} // namespace vector
