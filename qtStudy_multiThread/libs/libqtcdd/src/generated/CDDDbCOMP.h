#ifndef VECTOR_CDD_CDDDBCOMP_H
#define VECTOR_CDD_CDDDBCOMP_H

#include "CDDDbCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element COMP
 *
 */
class VECTOR_CDD_API CDDDbCOMP : public CDDDbCOMPImpl
{
public:
    CDDDbCOMP();
    ~CDDDbCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMP_H
