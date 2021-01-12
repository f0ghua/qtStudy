#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbECU;
class CDDDbAttrCats;
class CDDDbDefAtts;

/**
 * @brief element ECUDOC
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbECUDoc
{
public:
    CDDDbECUDoc();
    ~CDDDbECUDoc();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ATTRCATS */
    QSharedPointer<CDDDbAttrCats> m_attrcats;

    /** element DEFATTS */
    QSharedPointer<CDDDbDefAtts> m_defatts;

    /** element ECU */
    QSharedPointer<CDDDbECU> m_ecu;

};

} // namespace cdd
} // namespace vector
