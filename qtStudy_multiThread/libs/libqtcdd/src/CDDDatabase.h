#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class VECTOR_CDD_API CDDDatabase
{
public:
    CDDDatabase();
    ~CDDDatabase();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /** element ELEMENTS */


};

} // namespace cdd
} // namespace vector
