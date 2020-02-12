#ifndef FIBEXTYPES_H
#define FIBEXTYPES_H

#include <QMap>

namespace ASAM {
namespace FIBEX {

typedef QString HODesc;
typedef QString HOShortName;
typedef QString HOLongName;
typedef QString XSDuration;

class FibexTypes {
public:
    FibexTypes();

    template <typename T>
    class EnumParser
    {
    public:
        QMap<QString, T> enumMap;

        EnumParser();
        bool str2Enum(const QString &value, T &e)
        {
            typename QMap<QString, T>::const_iterator ci = enumMap.find(value);
            if (ci == enumMap.end())
                return false;
            e = ci.value();
            return true;
        }
    };

    /**
     * @brief simpleType FRAMETYPE
     *
     * To distinguish application frames from certain services
     */
    enum class FXFrameTypeSt {
        APPLICATION,
        BAP,
        DIAG_REQUEST,
        DIAG_RESPONSE,
        DIAG_STATE,
        NM,
        OTHER,
        SERVICE,
        TPL,
        XCP_PRE_CONFIGURED,
        XCP_RUNTIME_CONFIGURED
    };
    // static const char* const FXFrameTypeEl_enumString[];

    /**
     * @brief simpleType PDUTYPE
     *
     * To distinguish application data from certain services
     */
    enum class FXPduTypeSt {
        APPLICATION,
        BAP,
        DIAG_REQUEST,
        DIAG_RESPONSE,
        DIAG_STATE,
        NM,
        OTHER,
        SERVICE,
        TPL,
        XCP_PRE_CONFIGURED,
        XCP_RUNTIME_CONFIGURED
    };

    /**
     * @brief simpleType TYPE-TYPE
     *
     * General purpose of the signal
     */
    enum class FXTypeTypeSt {
        RESPONSE_ERROR,
        REQUEST,
        ALIVE_COUNTER,
        CHECKSUM,
        OTHER
    };

    /**
     * @brief KEY-SLOT-USAGE
     */
    enum class FRKeySlotUsageSt {
        STARTUP_SYNC,
        SYNC,
        NONE
    };

    /**
     * @brief COMPU-CATEGORY
     */
    enum class HOCompuCategorySt {
        IDENTICAL,
        LINEAR,
        SCALE_LINEAR,
        TEXTTABLE,
        BITFIELD_TEXTTABLE,
        TAB_NOINTP,
        FORMULA
    };

    /**
     * @brief INTERVAL-TYPE
     */
    enum class HOIntervalTypeAb {
        OPEN,
        CLOSED,
        INFINITE
    };

    /**
     * @brief fx:ACTIVE-CONDITION-SYSTEM-STATE-TYPE
     */
    enum class FXActiveConditionSystemStateType {
        CHANNEL_ACTIVE,
        CLAMP_15,
        CLAMP_30,
        CLAMP_87,
        CLAMP_RADIO,
        NONE,
        OTHER,
    };

    /**
     * @brief fx:EXECUTE-CONDITION-SIGNAL-STATE-TYPE
     */
    enum class FXExecuteConditionSignalStateType {
        VALUE_CHANGED,
        VALUE_NOT_CHANGED,
        VALUE_DEFAULT,
        VALUE_NOT_DEFAULT,
        OTHER,
    };

    /**
     * @brief fx:BIT-COUNTING-POLICY
     */
    enum class FXBitCountingPolicy {
        MONOTONE,
        SAWTOOTH,
    };

    /**
     * @brief fx:MEDIUM
     */
    enum class FXMedium {
        ELECTRICAL,
        OPTICAL,
        OTHER,
    };

};

} // FIBEX
} // ASAM

#endif // FIBEXTYPES_H
