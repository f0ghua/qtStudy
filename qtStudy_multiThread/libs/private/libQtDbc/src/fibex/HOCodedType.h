#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief element CODED-TYPE
 *
 * Coded Type of data on communication system.
 */
class VECTOR_DBC_EXPORT HOCodedType
{
public:
    HOCodedType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    QString m_baseDataType;
    QString m_category;
    QString m_encoding;

    quint32 m_bitLength;
    quint32 m_minLength;
    quint32 m_maxLength;

};

} // FIBEX
} // ASAM
