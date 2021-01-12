#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTuv;
/**
 * @brief element NAME
 *
 */
class VECTOR_CDD_API CDDDbTemplate
{
public:
    CDDDbTemplate();
    ~CDDDbTemplate();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element TUV */
    QSharedPointer<CDDDbTuv> m_tuv;

};

} // namespace cdd
} // namespace vector
