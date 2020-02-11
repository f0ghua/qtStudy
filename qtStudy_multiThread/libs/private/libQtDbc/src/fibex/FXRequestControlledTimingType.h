#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType REQUEST-CONTROLLED-TIMING-TYPE
 *
 * Content model for the entity TIMING in the request controlled peculiarity.
 */
class VECTOR_DBC_EXPORT RequestControlledTimingType
{
public:
    RequestControlledTimingType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element RESPONSE-TIME-RANGE */
    /** @todo element ACTIVE-CONDITION */
    /** @todo element FINAL-REPETITIONS */
    /** @todo element DESC */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
