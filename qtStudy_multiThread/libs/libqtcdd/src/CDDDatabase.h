#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbECUDOC;

class VECTOR_CDD_API CDDDatabase
{
public:
    CDDDatabase();
    ~CDDDatabase();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ECUDOC */
    QSharedPointer<CDDDbECUDOC> m_ecudoc;

};

} // namespace cdd
} // namespace vector
