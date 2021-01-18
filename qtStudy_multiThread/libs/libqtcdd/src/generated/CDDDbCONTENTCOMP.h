#ifndef VECTOR_CDD_CDDDBCONTENTCOMP_H
#define VECTOR_CDD_CDDDBCONTENTCOMP_H

#include "CDDDbCONTENTCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CONTENTCOMP
 *
 */
class VECTOR_CDD_API CDDDbCONTENTCOMP : public CDDDbCONTENTCOMPImpl
{
public:
    CDDDbCONTENTCOMP();
    ~CDDDbCONTENTCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONTENTCOMP_H
