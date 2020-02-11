#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType EVENT-CONTROLLED-TIMING-TYPE
 *
 * Content model for the entity TIMING in the event controlled peculiarity.
 */
class VECTOR_DBC_EXPORT FXEventControlledTimingType
{
public:
    FXEventControlledTimingType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element DEBOUNCE-TIME-RANGE */
    /** @todo element ACTIVE-CONDITION */
    /** @todo element SEND-CONDITION */
    /** @todo element FINAL-REPETITIONS */
    /** @todo element DESC */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
