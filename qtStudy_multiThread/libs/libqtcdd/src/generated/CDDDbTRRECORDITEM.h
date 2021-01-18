#ifndef VECTOR_CDD_CDDDBTRRECORDITEM_H
#define VECTOR_CDD_CDDDBTRRECORDITEM_H

#include "CDDDbTRRECORDITEMImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TRRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEM : public CDDDbTRRECORDITEMImpl
{
public:
    CDDDbTRRECORDITEM();
    ~CDDDbTRRECORDITEM();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEM_H
