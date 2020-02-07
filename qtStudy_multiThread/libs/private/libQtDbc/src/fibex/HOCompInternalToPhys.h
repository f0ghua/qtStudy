#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"
#include "FibexTypes.h"
#include "HOCompuScale.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType COMPU-METHODS
 *
 * Container for COMPU-METHOD elements
 */
class VECTOR_DBC_EXPORT HOCompInternalToPhys
{
public:
    HOCompInternalToPhys();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element ho:COMPU-SCALES */
    HOCompuScale m_compuScales;
    /** @todo element ho:COMPU-DEFAULT-VALUE */
};

} // FIBEX
} // ASAM
