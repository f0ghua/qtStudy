#ifndef VECTOR_CDD_CDDDBFAULTMEMORY_H
#define VECTOR_CDD_CDDDBFAULTMEMORY_H

#include "CDDDbFAULTMEMORYImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element FAULTMEMORY
 *
 */
class VECTOR_CDD_API CDDDbFAULTMEMORY : public CDDDbFAULTMEMORYImpl
{
public:
    CDDDbFAULTMEMORY();
    ~CDDDbFAULTMEMORY();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFAULTMEMORY_H
