#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXFrameType.h"
#include "FXPduType.h"
#include "FXSignalType.h"
#include "FXEcuType.h"

/*
#include "../fx/Extent.h"
#include "ChannelType.h"
#include "ClusterType.h"
#include "CompositeType.h"
#include "FunctionType.h"
#include "GatewayType.h"
*/

class QDomElement;

typedef int ClusterType;
typedef int ChannelType;
typedef int GatewayType;
typedef int EcuType;
typedef int FunctionType;
typedef int CompositeType;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType ELEMENTS
 *
 * Root of all stand-alone elements
 */
class VECTOR_DBC_EXPORT FXElements
{
public:
    FXElements();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /**
     * In multi-channel systems such as TTP or FlexRay known as 'bus'.
     * To avoid confusion, we decides not to use this term any more.
     */
    QList<ClusterType> m_clusterList;

    /**
     * In single-channel systems such as CAN or LIN known as 'bus'.
     * To avoid confusion, we decides not to use this term any more.
     */
    QList<ChannelType> m_channelList;

    /**
     * A gateway is a specific ECU translating frames and signals from one channel into another.
     * Further description of gateway behaviour is intended for a later version of FIBEX
     */
    QList<GatewayType> m_gatewayList;

    /** Electronic Control Unit (sometimes called 'node') */
    QList<FXEcuType> m_ecuList;

    QList<FXPduTypeCt> m_pduList;

    /**
     * Smallest piece of information exchanged over the communication system.
     * A frame normally consists of a header and a data (payload) section.
     * The data section contains signals.
     */
    QList<FXFrameTypeCt> m_frameList;

    /** Part of the application running in an ECU */
    QList<FunctionType> m_functionList;

    /** Smallest logical piece of information exchanged by applications */
    QList<FXSignalType> m_signalList;

    /** A hierarchical structure on functions or ecus. */
    QList<CompositeType> m_compositeList;
};

}
}
