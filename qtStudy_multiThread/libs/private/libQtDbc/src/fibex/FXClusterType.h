#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"
#include "FXRevisedElementType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CLUSTER-TYPE
 *
 * Content model for the entity CLUSTER with platform specific extendability.
 */
class VECTOR_DBC_EXPORT FXClusterType : public FXRevisedElementType
{
public:
    FXClusterType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element SPEED */
    quint64 m_speed;
    /** @todo element IS-HIGH-LOW-BIT-ORDER */
    bool isHighLowBitOrder;
    /** @todo element BIT-COUNTING-POLICY */
    FibexTypes::FXBitCountingPolicy m_bitCountingPolicy;
    /** @todo element PROTOCOL */
    QString m_protocol;
    /** @todo element PROTOCOL-VERSION */
    QString m_protocolVersion;
    /** @todo element PHYSICAL */
    QString m_physical;
    /** @todo element PHYSICAL-VERSION */
    QString m_physicalVersion;
    /** @todo element CHANNEL-REFS */
    QList<QString> m_channelRefList;
    /** @todo element MEDIUM */
    FibexTypes::FXMedium m_medium;
    /** @todo element NUMBER-OF-CYCLES */
    qint16 m_numberOfCycles;
    /** @todo element MAX-FRAME-LENGTH */
    quint32 m_maxFrameLength;
    /** @todo element fx:CAN-FD-SPEED */
    quint64 m_canFdSpeed;
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
