#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

/**
 * @brief element which defined with attribute id
 *
 * id element
 */
class VECTOR_CDD_API CDDDbAttrCatRefType
{
public:
    CDDDbAttrCatRefType();
    ~CDDDbAttrCatRefType();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString attrcatref() const {return m_attrcatref;}

    /** @must attribute attrcatref */
    QString m_attrcatref;

};

} // namespace cdd
} // namespace vector
