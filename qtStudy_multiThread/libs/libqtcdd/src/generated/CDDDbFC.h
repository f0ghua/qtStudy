#ifndef VECTOR_CDD_CDDDBFC_H
#define VECTOR_CDD_CDDDBFC_H

#include "CDDDbFCImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element FC
 *
 */
class VECTOR_CDD_API CDDDbFC : public CDDDbFCImpl
{
public:
    CDDDbFC();
    ~CDDDbFC();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFC_H
