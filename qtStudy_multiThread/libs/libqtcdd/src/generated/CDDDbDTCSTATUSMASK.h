#ifndef VECTOR_CDD_CDDDBDTCSTATUSMASK_H
#define VECTOR_CDD_CDDDBDTCSTATUSMASK_H

#include "CDDDbDTCSTATUSMASKImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DTCSTATUSMASK
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSMASK : public CDDDbDTCSTATUSMASKImpl
{
public:
    CDDDbDTCSTATUSMASK();
    ~CDDDbDTCSTATUSMASK();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSMASK_H
