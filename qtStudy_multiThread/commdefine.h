#ifndef COMMDEFINE_H
#define COMMDEFINE_H

#include <QPair>

#define CM_ERROR_IGNOR_COUNT        3

#define CM_POWER_NUMBER             2

#define CM_ELOAD_NUMBER             18
#define CM_ELOAD_CHANNEL_NUMBER     12

#define CM_RELAY_NUMBER             2
#define CM_RELAY_CIRCUIT_NUMBER     32

enum {
    CM_CTRLERELAY_ID        = 0,
    CM_CTRLFRELAY_ID        = 1
};

#define CM_PRODUCT_NUMBER           6
#define CM_PRODUCT_FUSE_NUMBER      54
#define CM_PRODUCT_RELAY_NUMBER     20

typedef int EloadVChannel;  // virtual channel number of eload
typedef int RelayVChannel;  // virtual circuit number of relay
typedef int FuseVid;        // virtual circuit number of relay
typedef int RelayVid;       // virtual circuit number of internal relay

#define CM_DEV_GETVCHANNEL(id, channel, max) ((id)*(max) + channel)
#define CM_DEV_GETID(vc, max) ((vc)/(max))
#define CM_DEV_GETCHANNEL(vc, max) ((vc)%(max))

#define CM_ELOAD_GETVCHANNEL(id, channel)   CM_DEV_GETVCHANNEL(id, channel, CM_ELOAD_CHANNEL_NUMBER)
#define CM_ELOAD_GETID(vc)                  CM_DEV_GETID(vc, CM_ELOAD_CHANNEL_NUMBER)
#define CM_ELOAD_GETCHANNEL(vc)             CM_DEV_GETCHANNEL(vc, CM_ELOAD_CHANNEL_NUMBER)

#define CM_RELAY_GETVCHANNEL(id, channel)   CM_DEV_GETVCHANNEL(id, channel, CM_RELAY_CIRCUIT_NUMBER)
#define CM_RELAY_GETID(vc)                  CM_DEV_GETID(vc, CM_RELAY_CIRCUIT_NUMBER)
#define CM_RELAY_GETCHANNEL(vc)             CM_DEV_GETCHANNEL(vc, CM_RELAY_CIRCUIT_NUMBER)

#define CM_FUSE_GETVID(product, id)         CM_DEV_GETVCHANNEL(product, id, CM_PRODUCT_FUSE_NUMBER)
#define CM_FUSE_GETPRODUCT(vc)              CM_DEV_GETID(vc, CM_PRODUCT_FUSE_NUMBER)
#define CM_FUSE_GETID(vc)                   CM_DEV_GETCHANNEL(vc, CM_PRODUCT_FUSE_NUMBER)

#define CM_FRELAY_GETVID(product, id)       CM_DEV_GETVCHANNEL(product, id, CM_PRODUCT_RELAY_NUMBER)
#define CM_FRELAY_GETPRODUCT(vc)            CM_DEV_GETID(vc, CM_PRODUCT_RELAY_NUMBER)
#define CM_FRELAY_GETID(vc)                 CM_DEV_GETCHANNEL(vc, CM_PRODUCT_RELAY_NUMBER)

#define CM_IDEV_SETVID(type, idx)           ((type << 16) | idx)
#define CM_IDEV_GETID(vid)                  (vid & 0xFFFF)
#define CM_IDEV_GETYPE(vid)                 ((vid >> 16) & 0xFFFF)

#define ELAOD_CURRENT_MEARANGE_MAX          20      // A
#define ELOAD_CURRENT_MAXVAL                11      // A

enum RelayState {
    RELAY_ST_CLOSE   = 0,
    RELAY_ST_OPEN,
    RELAY_ST_ALL
};

#define CM_RELAYST_NWORKING(ws) 		(((ws) == RELAY_ST_OPEN)?RELAY_ST_CLOSE:RELAY_ST_OPEN)
#define CM_RELAYST_WORKING(ws) 			(ws)
#define CM_RELAYST_GET(isWorking, ws) 	(isWorking?CM_RELAYST_WORKING(ws):CM_RELAYST_NWORKING(ws))

enum EloadType {
    ELOAD_TYPE_UNKNOWN   = 0,
    ELOAD_TYPE_SHARED,
    ELOAD_TYPE_PARALLEL,
    ELOAD_TYPE_SINGLE
};

enum WorkingStage {
    WSG_NONE            = 0,
    WSG_FVLDT_SELF,
    WSG_FVLDT,
    WSG_FUSING,
    WSG_FUSING_SELF
};

enum WorkingState {
    WST_IDLE            = 0,
    WST_PREPARING,
    WST_TESTING,
    WST_RESETING,
    WST_PAUSED
};

typedef QPair<RelayVChannel, RelayState> RelayStatePair;

#endif // COMMDEFINE_H
