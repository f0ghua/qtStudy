#pragma once
//  ----------------------------------------------------------------------------
//           INCLUDES
//  ----------------------------------------------------------------------------

#include <QString>
#include <QMap>
#include <QSharedPointer>
#include <QDebug>

//  ----------------------------------------------------------------------------
//           PUBLIC TYPES
//  ----------------------------------------------------------------------------

class QDomElement;

namespace vector {
namespace cdd {

//
// Since we based on Qt, we don't need to typedef for standard types such
// as double, int and so on.
//

typedef QString                 T_ASCIISTRING;
typedef QString                 T_UNICODESTRING;
typedef QVector<qint8>          T_BITFIELD;
typedef QVector<quint8>         T_BYTEFIELD;

enum class CDDUnsignedDataFormat {
    eDEC,
    eHEX
};

QDebug inline operator<<(QDebug d, const CDDUnsignedDataFormat &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << static_cast<quint32>(o);

    return d;
}

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

} // namespace cdd
} // namespace vector
