#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType UNIT
 *
 * ASAM unit definition
 */
class VECTOR_DBC_EXPORT Unit : public HONameDetails
{
public:
    Unit();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo attribute ID */
    /** @todo element ho:DISPLAY-NAME */
    /** @todo element ho:FACTOR-SI-TO-UNIT */
    /** @todo element ho:OFFSET-SI-TO-UNIT */
    /** @todo element ho:PHYSICAL-DIMENSION-REF */
};

} // FIBEX
} // ASAM
