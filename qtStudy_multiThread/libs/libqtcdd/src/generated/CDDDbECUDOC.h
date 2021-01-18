#ifndef VECTOR_CDD_CDDDBECUDOC_H
#define VECTOR_CDD_CDDDBECUDOC_H

#include "CDDDbECUDOCImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ECUDOC
 *
 */
class VECTOR_CDD_API CDDDbECUDOC : public CDDDbECUDOCImpl
{
public:
    CDDDbECUDOC();
    ~CDDDbECUDOC();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUDOC_H
