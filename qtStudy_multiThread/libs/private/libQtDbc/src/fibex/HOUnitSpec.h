#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOUnit.h"

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
    QList<HOUnit> m_unitList;
};

} // FIBEX
} // ASAM
