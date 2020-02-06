#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FRControllerType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType ECU-TYPE
 *
 * Content model for the entity ECU.
 * Platform-specific extensions are not possible, to maintain the capability to describe multi-platform networks.
 */
class VECTOR_DBC_EXPORT FXEcuType : public FXRevisedElementType
{
public:
    FXEcuType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element DIAGNOSTIC-ADDRESSES */
    /** @todo element FUNCTION-REFS */
    /** element CONTROLLERS */
    QList<FRControllerType> m_controllers;

    /** @todo element CONNECTORS */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
