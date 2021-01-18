#ifndef VECTOR_CDD_CDDDBCONSTCOMP_H
#define VECTOR_CDD_CDDDBCONSTCOMP_H

#include "CDDDbCONSTCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CONSTCOMP
 *
 */
class VECTOR_CDD_API CDDDbCONSTCOMP : public CDDDbCONSTCOMPImpl
{
public:
    CDDDbCONSTCOMP();
    ~CDDDbCONSTCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONSTCOMP_H
