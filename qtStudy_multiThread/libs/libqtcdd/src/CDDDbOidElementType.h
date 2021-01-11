#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbIdElementType.h"

namespace vector {
namespace cdd {

/**
 * @brief element which defined with attribute id
 *
 * id element
 */
class VECTOR_CDD_API CDDDbOidElementType : public CDDDbIdElementType
{
public:
    CDDDbOidElementType();
    ~CDDDbOidElementType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @must attribute oid */
    QString m_oid;

    /** @must attribute temploid */
    QString m_temploid;

};

} // namespace cdd
} // namespace vector
