#ifndef VECTOR_CDD_CDDDBTEXT_H
#define VECTOR_CDD_CDDDBTEXT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element TEXT
 *
 */
class VECTOR_CDD_API CDDDbTEXT
{
public:
    CDDDbTEXT();
    ~CDDDbTEXT();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXT_H
