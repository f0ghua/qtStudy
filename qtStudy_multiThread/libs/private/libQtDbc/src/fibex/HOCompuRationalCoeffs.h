#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType COMPU-RATIONAL-COEFFS
 *
 * ASAM rational coefficient.
 */
class VECTOR_DBC_EXPORT HOCompuRationalCoeffs
{
public:
    HOCompuRationalCoeffs();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:COMPU-NUMERATOR */
    QList<double> m_compuNumeratorList;
    /** element ho:COMPU-DENOMINATOR */
    QList<double> m_compuDenominatorList;
};

} // FIBEX
} // ASAM
