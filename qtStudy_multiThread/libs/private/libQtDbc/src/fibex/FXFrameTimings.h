#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType FRAME-TIMINGS
 *
 * Time behavior of a frame specified in a sequence of cluster specific timing types
 */
class VECTOR_DBC_EXPORT FXFrameTimings
{
public:
    FXFrameTimings();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element RELATIVELY-SCHEDULED-TIMING */
    /** @todo element ABSOLUTELY-SCHEDULED-TIMING */
};

} // FIBEX
} // ASAM
