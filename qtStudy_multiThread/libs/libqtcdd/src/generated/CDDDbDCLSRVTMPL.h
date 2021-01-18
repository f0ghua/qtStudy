#ifndef VECTOR_CDD_CDDDBDCLSRVTMPL_H
#define VECTOR_CDD_CDDDBDCLSRVTMPL_H

#include "CDDDbDCLSRVTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DCLSRVTMPL
 *
 */
class VECTOR_CDD_API CDDDbDCLSRVTMPL : public CDDDbDCLSRVTMPLImpl
{
public:
    CDDDbDCLSRVTMPL();
    ~CDDDbDCLSRVTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLSRVTMPL_H
