#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType FRAME-TRIGGERING-TYPE
 *
 * Content model for the entity FRAME-TRIGGERING.
 */
class VECTOR_DBC_EXPORT FXFrameTriggeringType
{
public:
    FXFrameTriggeringType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element TIMINGS */
    /** @todo element IDENTIFIER */
    /** @todo element FRAME-REF */
    /** @todo element MANUFACTURER-EXTENSION */
    /** @todo attribute ID */
};

} // FIBEX
} // ASAM

