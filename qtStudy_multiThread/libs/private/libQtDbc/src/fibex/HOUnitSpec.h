#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOUnit.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief element UNIT-SPEC
 *
 * Root element of ASAM unit specification.
 */
class VECTOR_DBC_EXPORT HOUnitSpec
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOUnitSpec(FXFibex *fibex = nullptr);
    ~HOUnitSpec();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element ho:ADMIN-DATA */
    /** @todo element ho:PHYSICAL-DIMENSIONS */
    /** @todo element ho:UNITGROUPS */
    /** @todo element ho:UNITS */
    QHash<QString, HOUnit*> m_units;
};

} // FIBEX
} // ASAM
