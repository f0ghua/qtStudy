#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXFrameTimings.h"
#include "FXIdentifier.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType FRAME-TRIGGERING-TYPE
 *
 * Content model for the entity FRAME-TRIGGERING.
 */
class VECTOR_DBC_EXPORT FXFrameTriggeringType
{
public:
    FXFrameTriggeringType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element TIMINGS */
    FXFrameTimings m_timings;
    /** @todo element IDENTIFIER */
    FXIdentifier m_identifier;
    /** @todo element FRAME-REF */
    QString m_frameRef;
    /** @todo element MANUFACTURER-EXTENSION */
    /** @todo attribute ID */
    QString m_id;
};

} // FIBEX
} // ASAM

