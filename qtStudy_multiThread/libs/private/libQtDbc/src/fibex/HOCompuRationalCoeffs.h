#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType COMPU-RATIONAL-COEFFS
 *
 * ASAM rational coefficient.
 */
class VECTOR_DBC_EXPORT HOCompuRationalCoeffs : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOCompuRationalCoeffs(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:COMPU-NUMERATOR */
    QList<double> m_compuNumeratorList;
    /** element ho:COMPU-DENOMINATOR */
    QList<double> m_compuDenominatorList;
};

} // FIBEX
} // ASAM
