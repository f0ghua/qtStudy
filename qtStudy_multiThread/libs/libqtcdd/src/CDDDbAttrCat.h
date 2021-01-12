#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNamedElementType.h"

namespace vector {
namespace cdd {

class CDDDbName;
class CDDDbDesc;
class CDDDbQual;

/**
 * @brief element ATTRCAT
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbAttrCat : public CDDDbNamedElementType
{
public:
    CDDDbAttrCat();
    ~CDDDbAttrCat();

    /** load from XML DOM element */
    void load(const QDomElement &element);
};

} // namespace cdd
} // namespace vector
