#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType PDU-TIMINGS
 *
 * Time behavior of a PDU specified in a sequence of cluster specific timing types
 */
class VECTOR_DBC_EXPORT FXPduTimings
{
public:
    FXPduTimings();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element CYCLIC-TIMING */
    /** @todo element EVENT-CONTROLLED-TIMING */
    /** @todo element REQUEST-CONTROLLED-TIMING */
};

} // FIBEX
} // ASAM

