#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNamedElementType.h"
#include "CDDDbAttrCatRefType.h"

namespace vector {
namespace cdd {

/**
 * @brief element CSTRDEF
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbCstrDef : public CDDDbNamedElementType, public CDDDbAttrCatRefType
{
public:
    CDDDbCstrDef();
    ~CDDDbCstrDef();

    /** load from XML DOM element */
    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector
