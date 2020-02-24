#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HONameDetails.h"
#include "FibexTypes.h"
#include "HOScaleConstrType.h"
#include "HOCompInternalToPhys.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief element COMPU-METHOD
 *
 * Method to calulate the transmitted value to the physical representation
 */
class VECTOR_DBC_EXPORT HOCompuMethod : public HONameDetails, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOCompuMethod(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:CATEGORY */
    FibexTypes::HOCompuCategorySt m_compuCategory;
    /** element ho:UNIT-REF */
    QString m_unitRef;
    /** element ho:PHYS-CONSTRS */
    HOScaleConstrType m_physConstrs;
    /** element ho:INTERNAL-CONSTRS */
    HOScaleConstrType m_internalConstrs;
    /** element ho:COMPU-INTERNAL-TO-PHYS */
    HOCompInternalToPhys *m_compuInternalToPhys = nullptr;
    /** @todo element ho:DESC */
};

} // FIBEX
} // ASAM
