#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType SIGNAL-TYPE-TYPE
 *
 * General category (type) of a SIGNAL
 */
class VECTOR_DBC_EXPORT FXSignalTypeType
{
public:
    FXSignalTypeType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element TYPE */
    FibexTypes::FXTypeTypeSt m_type;
    /** element METHOD */
    QString m_method;

    /** @todo element ATTRIBUTES */
};

} // FIBEX
} // ASAM
