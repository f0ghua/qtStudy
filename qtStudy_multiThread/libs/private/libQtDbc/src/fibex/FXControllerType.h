#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXNamedElementType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CONTROLLER-TYPE
 *
 * Content model for the entity CONTROLLER with platform specific extendability.
 */
class VECTOR_DBC_EXPORT FXControllerType : public FXNamedElementType
{
public:
    FXControllerType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /**
     * @brief VENDOR-NAME
     *
     * For hardware classification
     */
    QString m_vendorName;

    /**
     * @brief CHIP-NAME
     *
     * For hardware classification
     */
    QString m_chipName;

    /**
     * @brief TERMINATION-IMPEDANCE
     *
     * A controllers termination impedance (same on all channels)
     */
    quint64 m_terminationImpedance;

    /**
     * @brief TRANSCEIVER
     *
     * A controllers transceiver
     */
    QString m_transceiver;

    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
