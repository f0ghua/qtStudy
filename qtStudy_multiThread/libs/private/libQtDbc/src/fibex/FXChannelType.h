#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FXPduTriggeringType.h"
#include "FXFrameTriggeringType.h"

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
    QList<FXPduTriggeringType> m_pduTriggeringList;
    /** @todo element FRAME-TRIGGERINGS */
    QList<FXFrameTriggeringType> m_frameTriggeringList;
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
