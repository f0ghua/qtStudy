#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType UNIT
 *
 * ASAM unit definition
 */
class VECTOR_DBC_EXPORT HOUnit : public HONameDetails
{
public:
    HOUnit();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;
    /** element ho:DISPLAY-NAME */
    QString m_displayName;
    /** element ho:FACTOR-SI-TO-UNIT */
    double m_factorSiToUnit;
    /** element ho:OFFSET-SI-TO-UNIT */
    double m_offsetSiToUnit;
    /** element ho:PHYSICAL-DIMENSION-REF */
    QString m_physicalDimensionRef;
};

} // FIBEX
} // ASAM
