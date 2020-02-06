#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType INCLUDED-SIGNAL-TYPE
 *
 * Selected signal
 */
class VECTOR_DBC_EXPORT FXIncludedSignalType
{
public:
    FXIncludedSignalType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element SIGNAL-INSTANCE-REF */
    QString m_signalInstanceRef;
};

} // FIBEX
} // ASAM
