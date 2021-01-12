#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbECUAtts;
/**
 * @brief element NAME
 *
 */
class VECTOR_CDD_API CDDDbDefAtts
{
public:
    CDDDbDefAtts();
    ~CDDDbDefAtts();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ECUATTS */
    QSharedPointer<CDDDbECUAtts> m_ecuatts;

};

} // namespace cdd
} // namespace vector
