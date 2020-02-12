#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXSystemTrigger.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType ACTIVE-CONDITION-TYPE
 *
 * For reusability active conditions content model is specified using a type definition.
 */
class VECTOR_DBC_EXPORT FXActiveConditionType
{
public:
    FXActiveConditionType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element SYSTEM-TRIGGER */
    QList<FXSystemTrigger> m_systemTriggerList;
};

} // FIBEX
} // ASAM
