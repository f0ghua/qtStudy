#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType NAMED-ELEMENT-TYPE
 *
 * Base content model for all ELEMENTS
 */
class VECTOR_DBC_EXPORT FXNamedElementType : public HONameDetails
{
public:
    FXNamedElementType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;

    /** @todo attribute OID */
};

}
}
