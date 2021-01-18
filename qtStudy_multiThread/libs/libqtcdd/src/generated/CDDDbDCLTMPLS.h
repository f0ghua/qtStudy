#ifndef VECTOR_CDD_CDDDBDCLTMPLS_H
#define VECTOR_CDD_CDDDBDCLTMPLS_H

#include "CDDDbDCLTMPLSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DCLTMPLS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLS : public CDDDbDCLTMPLSImpl
{
public:
    CDDDbDCLTMPLS();
    ~CDDDbDCLTMPLS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPLS_H
