#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXSignalInstanceType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType SIGNAL-INSTANCES
 *
 * A PDUs layout as a sequence of Signal-Instances
 */
class VECTOR_DBC_EXPORT FXSignalInstances
{
public:
    FXSignalInstances();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element SIGNAL-INSTANCE */
    QList<FXSignalInstanceType> m_sigInstanceList;
};

} // FIBEX
} // ASAM
