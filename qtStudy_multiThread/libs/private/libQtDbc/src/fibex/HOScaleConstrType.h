#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOScaleConstr.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType SCALE-CONSTR-TYPE
 *
 * For reusability scale constraints content model is specified using a type definition.
 */
class VECTOR_DBC_EXPORT HOScaleConstrType
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOScaleConstrType(FXFibex *fibex = nullptr);
    ~HOScaleConstrType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @opt element ho:LOWER-LIMIT */
    double *m_lowerLimit = nullptr;
    /** attribute ho:LOWER-LIMIT ho:INTERVAL-TYPE */
    FibexTypes::HOIntervalTypeAb m_lowerLimitIntervalType;
    /** @opt element ho:UPPER-LIMIT */
    double *m_upperLimit = nullptr;
    /** attribute ho:UPPER-LIMIT ho:INTERVAL-TYPE */
    FibexTypes::HOIntervalTypeAb m_upperLimitIntervalType;
    /** element ho:SCALE-CONSTR */
    HOScaleConstr *m_scaleConstr = nullptr;
};

} // FIBEX
} // ASAM
