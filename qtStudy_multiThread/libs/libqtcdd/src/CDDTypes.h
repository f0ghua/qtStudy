#pragma once
//  ----------------------------------------------------------------------------
//           INCLUDES
//  ----------------------------------------------------------------------------

#include <QString>
#include <QMap>
#include <QSharedPointer>

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

} // namespace cdd
} // namespace vector
