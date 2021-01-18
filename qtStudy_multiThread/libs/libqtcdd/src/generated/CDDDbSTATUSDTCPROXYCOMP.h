#ifndef VECTOR_CDD_CDDDBSTATUSDTCPROXYCOMP_H
#define VECTOR_CDD_CDDDBSTATUSDTCPROXYCOMP_H

#include "CDDDbSTATUSDTCPROXYCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATUSDTCPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbSTATUSDTCPROXYCOMP : public CDDDbSTATUSDTCPROXYCOMPImpl
{
public:
    CDDDbSTATUSDTCPROXYCOMP();
    ~CDDDbSTATUSDTCPROXYCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATUSDTCPROXYCOMP_H
