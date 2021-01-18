#ifndef VECTOR_CDD_CDDDBNUMITERCOMP_H
#define VECTOR_CDD_CDDDBNUMITERCOMP_H

#include "CDDDbNUMITERCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NUMITERCOMP
 *
 */
class VECTOR_CDD_API CDDDbNUMITERCOMP : public CDDDbNUMITERCOMPImpl
{
public:
    CDDDbNUMITERCOMP();
    ~CDDDbNUMITERCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNUMITERCOMP_H
