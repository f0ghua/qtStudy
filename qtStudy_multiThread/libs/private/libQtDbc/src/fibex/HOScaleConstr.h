#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType SCALE-CONSTR
 *
 * For reusability scale constraints content model is specified using a type
 * definition.
 *
 */
class VECTOR_DBC_EXPORT HOScaleConstr
{
public:
    HOScaleConstr();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:LOWER-LIMIT */
    double m_lowerLimit;
    /** attribute ho:LOWER-LIMIT ho:INTERVAL-TYPE */
    FibexTypes::HOIntervalTypeAb m_lowerLimitIntervalType;
    /** element ho:UPPER-LIMIT */
    double m_upperLimit;
    /** attribute ho:UPPER-LIMIT ho:INTERVAL-TYPE */
    FibexTypes::HOIntervalTypeAb m_upperLimitIntervalType;
};

} // FIBEX
} // ASAM
