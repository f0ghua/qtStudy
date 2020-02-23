#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType COMPU-SCALE
 *
 * Domain and computition rule to convert an internal data (transmitted over
 * the communication system) into phyiscal data of an application.
 *
 */
class VECTOR_DBC_EXPORT HOCompuScale : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOCompuScale(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element ho:SHORT-LABEL */
    /** @todo element ho:DESC */
    /** @todo element ho:MASK */
    /** @todo element ho:LOWER-LIMIT */
    /** @todo element ho:UPPER-LIMIT */
    /** @todo element ho:COMPU-CONST */
    /** @todo element ho:COMPU-RATIONAL-COEFFS */
    /** @todo element ho:COMPU-GENERIC-MATH */
};

} // FIBEX
} // ASAM
