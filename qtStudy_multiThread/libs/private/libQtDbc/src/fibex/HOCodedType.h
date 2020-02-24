#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief element CODED-TYPE
 *
 * Coded Type of data on communication system.
 */
class VECTOR_DBC_EXPORT HOCodedType : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOCodedType(FXFibex *fibex, QObject *parent = Q_NULLPTR);
    ~HOCodedType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    FibexTypes::HOBaseDataType *m_baseDataType = nullptr;
    QString m_category;
    QString m_encoding;

    quint32 m_bitLength;
    quint32 m_minLength;
    quint32 m_maxLength;

};

} // FIBEX
} // ASAM
