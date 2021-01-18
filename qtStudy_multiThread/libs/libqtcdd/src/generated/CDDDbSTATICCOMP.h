#ifndef VECTOR_CDD_CDDDBSTATICCOMP_H
#define VECTOR_CDD_CDDDBSTATICCOMP_H

#include "CDDDbSTATICCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATICCOMP
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMP : public CDDDbSTATICCOMPImpl
{
public:
    CDDDbSTATICCOMP();
    ~CDDDbSTATICCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMP_H
