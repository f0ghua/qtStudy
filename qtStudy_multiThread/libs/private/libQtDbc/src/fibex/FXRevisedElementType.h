#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXNamedElementType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType REVISED-ELEMENT-TYPE
 *
 * Base content model for all ELEMENTS
 */
class VECTOR_DBC_EXPORT FXRevisedElementType : public FXNamedElementType
{
public:
    FXRevisedElementType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element ELEMENT-REVISIONS */
    /** @todo element PRODUCT-REF */
};

}
}

