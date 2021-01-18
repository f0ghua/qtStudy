#ifndef VECTOR_CDD_CDDDBRECORDTMPLS_H
#define VECTOR_CDD_CDDDBRECORDTMPLS_H

#include "CDDDbRECORDTMPLSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDTMPLS
 *
 */
class VECTOR_CDD_API CDDDbRECORDTMPLS : public CDDDbRECORDTMPLSImpl
{
public:
    CDDDbRECORDTMPLS();
    ~CDDDbRECORDTMPLS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPLS_H
