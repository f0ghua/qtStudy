#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOUnitSpec.h"
#include "FXCodings.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType PROCESSING-INFORMATION
 *
 * Data needed to process data in elements.
 */
class VECTOR_DBC_EXPORT FXProcessingInformation
{
public:
    FXProcessingInformation();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element UNIT-SPEC */
    HOUnitSpec m_unitSpec;
    /** element CODINGS */
    FXCodings m_codings;
};

} // FIBEX
} // ASAM
