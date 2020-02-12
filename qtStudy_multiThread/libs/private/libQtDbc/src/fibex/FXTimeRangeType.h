#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType TIME-RANGE-TYPE
 *
 * For reusability time ranges content model is specified using a type definition.
 */
class VECTOR_DBC_EXPORT FXTimeRangeType
{
public:
    FXTimeRangeType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element VALUE */
    QString m_value;
    /** @todo element TOLERANCE */
};

} // FIBEX
} // ASAM
