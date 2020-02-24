#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FXSignalInstances.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType PDU-TYPE
 *
 * Content model for the entity PDU.
 */
class VECTOR_DBC_EXPORT FXPduTypeCt : public FXRevisedElementType, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXPduTypeCt(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element BYTE-LENGTH */
    quint32 m_byteLength;
    /** element PDU-TYPE */
    FibexTypes::FXPduTypeSt m_pduType;
    /** element SIGNAL-INSTANCES */
    FXSignalInstances *m_sigInstances = nullptr;

    /** @todo element MULTIPLEXER */
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
