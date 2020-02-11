#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CYCLIC-TIMING-TYPE
 *
 * Content model for the entity TIMING in the cyclic peculiarity.
 */
class VECTOR_DBC_EXPORT FXCyclicTimingType
{
public:
    FXCyclicTimingType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element REPEATING-TIME-RANGE */
    /** @todo element STARTING-TIME-RANGE */
    /** @todo element ACTIVE-CONDITION */
    /** @todo element START-CONDITION */
    /** @todo element STOP-CONDITION */
    /** @todo element FINAL-REPETITIONS */
    /** @todo element DESC */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
