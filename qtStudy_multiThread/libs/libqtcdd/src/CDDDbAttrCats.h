#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbAttrCat;

/**
 * @brief element ATTRCATS
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbAttrCats
{
public:
    CDDDbAttrCats();
    ~CDDDbAttrCats();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ATTRCAT */
    QMap<QString, QSharedPointer<CDDDbAttrCat>> m_attrcats;

};

} // namespace cdd
} // namespace vector
