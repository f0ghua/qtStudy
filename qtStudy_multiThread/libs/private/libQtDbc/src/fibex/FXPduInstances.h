#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXPduInstanceType.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType PDU-INSTANCES
 *
 * A frames layout as a sequence of PDUs
 */
class VECTOR_DBC_EXPORT FXPduInstances
{
public:
    FXPduInstances();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    QList<FXPduInstanceType> m_pduInstanceList;
    /** @todo element PDU-INSTANCE */
};

}
}
