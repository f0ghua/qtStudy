#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "HOCodedType.h"
#include "HOCompuMethods.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CODING-TYPE
 *
 * Content model for the entity CODING.
 */
class VECTOR_DBC_EXPORT CodingType : public FXRevisedElementType
{
public:
    CodingType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element PHYSICAL-TYPE */
    /** element CODED-TYPE */
    HOCodedType m_codedType;
    /** @todo element COMPU-METHODS */
    HOCompuMethods m_compuMethods;
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
