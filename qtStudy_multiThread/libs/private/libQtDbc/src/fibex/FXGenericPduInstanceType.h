#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType GENERIC-PDU-INSTANCE-TYPE
 *
 * Content model for the entity PDU-INSTANCE.
 */
class VECTOR_DBC_EXPORT FXGenericPduInstanceType
{
public:
    FXGenericPduInstanceType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;
    /** element PDU-REF */
    QString m_idRef;

    /** @todo element MANUFACTURER-EXTENSION */

};

}
}
