#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"
#include "FibexTypes.h"
#include "HOScaleConstrType.h"
#include "HOCompInternalToPhys.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType COMPU-METHODS
 *
 * Container for COMPU-METHOD elements
 */
class VECTOR_DBC_EXPORT HOCompuMethods : public HONameDetails
{
public:
    HOCompuMethods();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:CATEGORY */
    FibexTypes::HOCompuCategorySt m_compuCategory;
    /** element ho:UNIT-REF */
    QString m_unitRef;
    /** element ho:PHYS-CONSTRS */
    HOScaleConstrType m_physConstrs;
    /** element ho:INTERNAL-CONSTRS */
    HOScaleConstrType m_internalConstrs;
    /** @todo element ho:COMPU-INTERNAL-TO-PHYS */
    HOCompInternalToPhys m_compuInternalToPhys;
    /** @todo element ho:DESC */
};

} // FIBEX
} // ASAM
