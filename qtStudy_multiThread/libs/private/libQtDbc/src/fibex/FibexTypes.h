#ifndef FIBEXTYPES_H
#define FIBEXTYPES_H

#include <QMap>

namespace ASAM {
namespace FIBEX {

typedef QString HODesc;
typedef QString HOShortName;
typedef QString HOLongName;

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
};

}
}

#endif // FIBEXTYPES_H
