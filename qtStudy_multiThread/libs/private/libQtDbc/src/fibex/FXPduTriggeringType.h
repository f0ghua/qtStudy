#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType PDU-TRIGGERING-TYPE
 *
 * Content model for the entity PDU-TRIGGERING.
 */
class VECTOR_DBC_EXPORT FXPduTriggeringType
{
public:
    FXPduTriggeringType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element TIMINGS */
    /** @todo element PDU-REF */
    /** @todo element MANUFACTURER-EXTENSION */
    /** @todo attribute ID */
    QString m_id;
};

} // FIBEX
} // ASAM
