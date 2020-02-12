#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXPduTimings.h"

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
    FXPduTimings m_timings;
    /** @todo element PDU-REF */
    QString m_pduRef;
    /** @todo element MANUFACTURER-EXTENSION */
    /** @todo attribute ID */
    QString m_id;
};

} // FIBEX
} // ASAM
