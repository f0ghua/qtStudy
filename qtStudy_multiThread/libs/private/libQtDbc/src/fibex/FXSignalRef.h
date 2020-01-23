#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType/element SIGNAL-REF
 *
 * Refering a signal
 */
class VECTOR_DBC_EXPORT FXSignalRef
{
public:
    FXSignalRef();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID-REF */
    QString m_idRef;
};

} // FIBEX
} // ASAM
