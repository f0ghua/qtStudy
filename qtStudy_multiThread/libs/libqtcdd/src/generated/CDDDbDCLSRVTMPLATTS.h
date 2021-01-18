#ifndef VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H
#define VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H

#include "CDDDbDCLSRVTMPLATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DCLSRVTMPLATTS
 *
 */
class VECTOR_CDD_API CDDDbDCLSRVTMPLATTS : public CDDDbDCLSRVTMPLATTSImpl
{
public:
    CDDDbDCLSRVTMPLATTS();
    ~CDDDbDCLSRVTMPLATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H
