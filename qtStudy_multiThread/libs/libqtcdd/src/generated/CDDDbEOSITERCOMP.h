#ifndef VECTOR_CDD_CDDDBEOSITERCOMP_H
#define VECTOR_CDD_CDDDBEOSITERCOMP_H

#include "CDDDbEOSITERCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element EOSITERCOMP
 *
 */
class VECTOR_CDD_API CDDDbEOSITERCOMP : public CDDDbEOSITERCOMPImpl
{
public:
    CDDDbEOSITERCOMP();
    ~CDDDbEOSITERCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEOSITERCOMP_H
