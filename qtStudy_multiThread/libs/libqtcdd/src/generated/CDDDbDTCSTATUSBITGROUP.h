#ifndef VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H
#define VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H

#include "CDDDbDTCSTATUSBITGROUPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DTCSTATUSBITGROUP
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSBITGROUP : public CDDDbDTCSTATUSBITGROUPImpl
{
public:
    CDDDbDTCSTATUSBITGROUP();
    ~CDDDbDTCSTATUSBITGROUP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H
