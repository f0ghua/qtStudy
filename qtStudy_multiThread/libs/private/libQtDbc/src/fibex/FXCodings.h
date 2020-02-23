#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXCodingType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CODINGS
 *
 * Top level element of all codings
 */
class VECTOR_DBC_EXPORT FXCodings
{
public:
    FXCodings();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element CODING */
    QHash<QString, CodingType> m_codings;
};

} // FIBEX
} // ASAM
