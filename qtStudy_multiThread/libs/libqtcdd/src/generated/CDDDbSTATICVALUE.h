#ifndef VECTOR_CDD_CDDDBSTATICVALUE_H
#define VECTOR_CDD_CDDDBSTATICVALUE_H

#include "CDDDbSTATICVALUEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATICVALUE
 *
 */
class VECTOR_CDD_API CDDDbSTATICVALUE : public CDDDbSTATICVALUEImpl
{
public:
    CDDDbSTATICVALUE();
    ~CDDDbSTATICVALUE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICVALUE_H
