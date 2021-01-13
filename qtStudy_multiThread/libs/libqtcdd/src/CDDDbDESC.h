#ifndef VECTOR_CDD_CDDDBDESC_H
#define VECTOR_CDD_CDDDBDESC_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element DESC
 *
 */
class VECTOR_CDD_API CDDDbDESC
{
public:
    CDDDbDESC();
    ~CDDDbDESC();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDESC_H
