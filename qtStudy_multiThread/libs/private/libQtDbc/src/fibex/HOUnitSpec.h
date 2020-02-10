#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief element UNIT-SPEC
 *
 * Root element of ASAM unit specification.
 */
class VECTOR_DBC_EXPORT HOUnitSpec
{
public:
    HOUnitSpec();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element ho:ADMIN-DATA */
    /** @todo element ho:PHYSICAL-DIMENSIONS */
    /** @todo element ho:UNITGROUPS */
    /** @todo element ho:UNITS */
};

} // FIBEX
} // ASAM
