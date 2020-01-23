#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXFrameType.h"
#include "FXPduType.h"
#include "FXSignalType.h"

/*
#include "../fx/Extent.h"
#include "ChannelType.h"
#include "ClusterType.h"
#include "CompositeType.h"
#include "EcuType.h"
#include "FrameType.h"
#include "FunctionType.h"
#include "GatewayType.h"
#include "PduType.h"
#include "SignalType.h"
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

    struct Clusters {
        Clusters();

        /**
         * In multi-channel systems such as TTP or FlexRay known as 'bus'.
         * To avoid confusion, we decides not to use this term any more.
         */
        QList<ClusterType> m_cluster;
    };

    /** Top level element of all clusters */
    QList<Clusters> m_clusters;

    struct Channels {
        Channels();

        /**
         * In single-channel systems such as CAN or LIN known as 'bus'.
         * To avoid confusion, we decides not to use this term any more.
         */
        QList<ChannelType> m_channel;
    };

    /** Top level element of all channels */
    QList<Channels> m_channels;

    struct Gateways {
        Gateways();

        /**
         * A gateway is a specific ECU translating frames and signals from one channel into another.
         * Further description of gateway behaviour is intended for a later version of FIBEX
         */
        QList<GatewayType> m_gateway;
    };

    /** Top level element of all gateways */
    QList<Gateways> m_gateways;

    struct Ecus {
        Ecus();

        /** Electronic Control Unit (sometimes called 'node') */
        QList<EcuType> m_ecu;
    };

    /** Top level element of all ECUs */
    QList<Ecus> m_ecus;

    struct Pdus {
        Pdus();

        QList<FXPduTypeCt> m_pduList;
    };

    /** Top level element of all PDUs */
    QList<Pdus> m_pdusList;

    struct Frames {
        Frames();

        /**
         * Smallest piece of information exchanged over the communication system.
         * A frame normally consists of a header and a data (payload) section.
         * The data section contains signals.
         */
        QList<FXFrameTypeCt> m_frameList;
    };

    /** Top level element of all frames */
    QList<Frames> m_framesList;

    struct Functions {
        Functions();

        /** Part of the application running in an ECU */
        QList<FunctionType> m_function;
    };

    /** Top level element of all functions */
    QList<Functions> m_functions;

    struct Signals {
        Signals();

        /** Smallest logical piece of information exchanged by applications */
        QList<FXSignalType> m_sigList;
    };

    /** Top level element of all signals */
    QList<Signals> m_signalsList;

    struct Composites {
        Composites();

        /** A hierarchical structure on functions or ecus. */
        QList<CompositeType> m_composite;
    };

    /** Top level element of all composites */
    QList<Composites> m_composites;
};

}
}
