#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXSystemTrigger.h"
#include "FXSignalTrigger.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType EXECUTE-CONDITION-TYPE
 *
 * For reusability execute conditions content model is specified using a type definition.
 */
class VECTOR_DBC_EXPORT FXExecuteConditionType
{
public:
    FXExecuteConditionType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element SYSTEM-TRIGGER */
    QList<FXSystemTrigger> m_systemTriggerList;
    /** @todo element SIGNAL-TRIGGER */
    QList<FXSignalTrigger> m_signalTriggerList;
};

} // FIBEX
} // ASAM
