#ifndef VECTOR_CDD_CDDDBEXCL_H
#define VECTOR_CDD_CDDDBEXCL_H

#include "CDDDbEXCLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element EXCL
 *
 */
class VECTOR_CDD_API CDDDbEXCL : public CDDDbEXCLImpl
{
public:
    CDDDbEXCL();
    ~CDDDbEXCL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXCL_H
