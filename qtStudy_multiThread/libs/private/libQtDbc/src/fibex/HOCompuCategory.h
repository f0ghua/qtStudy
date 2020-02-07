#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief simpleType COMPU-CATEGORY
 *
 * Type of the compu method
 */
class VECTOR_DBC_EXPORT HOCompuCategory
{
public:
    HOCompuCategory();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @brief COMPU-CATEGORY */
    FibexTypes::HOCompuCategorySt m_compuCategory;
};

} // FIBEX
} // ASAM
