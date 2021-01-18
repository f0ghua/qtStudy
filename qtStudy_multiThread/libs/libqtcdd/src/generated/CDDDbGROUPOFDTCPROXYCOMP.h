#ifndef VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H
#define VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H

#include "CDDDbGROUPOFDTCPROXYCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element GROUPOFDTCPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbGROUPOFDTCPROXYCOMP : public CDDDbGROUPOFDTCPROXYCOMPImpl
{
public:
    CDDDbGROUPOFDTCPROXYCOMP();
    ~CDDDbGROUPOFDTCPROXYCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H
