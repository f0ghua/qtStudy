#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType INCLUDED-SIGNAL-TYPE
 *
 * Selected signal
 */
class VECTOR_DBC_EXPORT FXIncludedSignalType : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXIncludedSignalType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element SIGNAL-INSTANCE-REF */
    QString m_signalInstanceRef;
};

} // FIBEX
} // ASAM
