#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXConnectorType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CONNECTOR-TYPE
 */
class VECTOR_DBC_EXPORT FRConnectorType : public FXConnectorType
{
public:
    FRConnectorType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element WAKE-UP-CHANNEL */
    bool m_wakeUpChannel;
};

} // FIBEX
} // ASAM
