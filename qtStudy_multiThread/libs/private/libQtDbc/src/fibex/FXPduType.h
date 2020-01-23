#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FXSignalInstances.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType PDU-TYPE
 *
 * Content model for the entity PDU.
 */
class VECTOR_DBC_EXPORT FXPduTypeCt : public FXRevisedElementType
{
public:
    FXPduTypeCt();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element BYTE-LENGTH */
    quint32 m_byteLength;
    /** element PDU-TYPE */
    FibexTypes::FXPduTypeSt m_pduType;
    /** element SIGNAL-INSTANCES */
    FXSignalInstances m_sigInstances;

    /** @todo element MULTIPLEXER */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
