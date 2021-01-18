#ifndef VECTOR_CDD_CDDDBSIMPLEPROXYCOMP_H
#define VECTOR_CDD_CDDDBSIMPLEPROXYCOMP_H

#include "CDDDbSIMPLEPROXYCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SIMPLEPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbSIMPLEPROXYCOMP : public CDDDbSIMPLEPROXYCOMPImpl
{
public:
    CDDDbSIMPLEPROXYCOMP();
    ~CDDDbSIMPLEPROXYCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSIMPLEPROXYCOMP_H
