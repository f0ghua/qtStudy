#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"
#include "FXRevisedElementType.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType fx:CLUSTER-TYPE
 *
 * Content model for the entity CLUSTER with platform specific extendability.
 */
class VECTOR_DBC_EXPORT FXClusterType : public FXRevisedElementType
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXClusterType(FXFibex *fibex);
    ~FXClusterType();

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
    /** @opt element PROTOCOL-VERSION */
    QString *m_protocolVersion = nullptr;
    /** @opt element PHYSICAL */
    QString *m_physical = nullptr;
    /** @todo element PHYSICAL-VERSION */
    QString *m_physicalVersion = nullptr;
    /** @todo element CHANNEL-REFS */
    QList<QString> m_channelRefList;
    /** @todo element MEDIUM */
    FibexTypes::FXMedium *m_medium = nullptr;
    /** @todo element NUMBER-OF-CYCLES */
    qint16 *m_numberOfCycles = nullptr;
    /** @todo element MAX-FRAME-LENGTH */
    quint32 *m_maxFrameLength = nullptr;
    /** @todo element fx:CAN-FD-SPEED */
    quint64 *m_canFdSpeed = nullptr;
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM
