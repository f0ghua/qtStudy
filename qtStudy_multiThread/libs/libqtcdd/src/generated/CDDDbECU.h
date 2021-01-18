#ifndef VECTOR_CDD_CDDDBECU_H
#define VECTOR_CDD_CDDDBECU_H

#include "CDDDbECUImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ECU
 *
 */
class VECTOR_CDD_API CDDDbECU : public CDDDbECUImpl
{
public:
    CDDDbECU();
    ~CDDDbECU();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECU_H
