#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXCommonLayoutDetails.h"
#include "FXSignalRef.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType SIGNAL-INSTANCE-TYPE
 *
 * Content model for the entity SIGNAL-INSTANCE
 */
class VECTOR_DBC_EXPORT FXSignalInstanceType
{
public:
    FXSignalInstanceType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;
    /** group COMMON-LAYOUT-DETAILS */
    FXCommonLayoutDetails m_commLayoutDetails;
    /** element SIGNAL-REF */
    FXSignalRef m_sigRef;
    /** element SIGNAL-UPDATE-BIT-POSITION */
    quint32 m_signalUpdateBitPosition;

    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
