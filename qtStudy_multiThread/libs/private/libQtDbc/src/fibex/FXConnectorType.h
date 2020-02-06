#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXEcuPortType.h"

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

    /** element CHANNEL-REF */
    QString m_channelRef;
    /** element CONTROLLER-REF */
    QString m_controllerRef;
    /** element INPUTS */
    QList<FXEcuPortType> m_inputPortList;
    /** element OUTPUTS */
    QList<FXEcuPortType> m_outputPortList;
    /** @todo element MANUFACTURER-EXTENSION */

};

} // FIBEX
} // ASAM
