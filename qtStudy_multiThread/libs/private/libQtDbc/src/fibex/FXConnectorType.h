#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CONNECTOR-TYPE
 *
 * Content model for the entity CONNECTOR with platform specific extendability.
 */
class VECTOR_DBC_EXPORT FXConnectorType
{
public:
    FXConnectorType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;
    /** @todo element CHANNEL-REF */
    /** @todo element CONTROLLER-REF */
    /** @todo element INPUTS */
    /** @todo element OUTPUTS */
    /** @todo element MANUFACTURER-EXTENSION */

};

} // FIBEX
} // ASAM
