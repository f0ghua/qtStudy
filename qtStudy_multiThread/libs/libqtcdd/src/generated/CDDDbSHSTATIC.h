#ifndef VECTOR_CDD_CDDDBSHSTATIC_H
#define VECTOR_CDD_CDDDBSHSTATIC_H

#include "CDDDbSHSTATICImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHSTATIC
 *
 */
class VECTOR_CDD_API CDDDbSHSTATIC : public CDDDbSHSTATICImpl
{
public:
    CDDDbSHSTATIC();
    ~CDDDbSHSTATIC();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHSTATIC_H
