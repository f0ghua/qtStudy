#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CHANNEL-TYPE
 *
 * Content model for the entity CHANNEL with platform specific extendability.
 */
class VECTOR_DBC_EXPORT FXChannelType : public FXRevisedElementType
{
public:
    FXChannelType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element PDU-TRIGGERINGS */
    /** @todo element FRAME-TRIGGERINGS */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
