#ifndef VECTOR_CDD_CDDDBUNSRECORDITEM_H
#define VECTOR_CDD_CDDDBUNSRECORDITEM_H

#include "CDDDbUNSRECORDITEMImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNSRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbUNSRECORDITEM : public CDDDbUNSRECORDITEMImpl
{
public:
    CDDDbUNSRECORDITEM();
    ~CDDDbUNSRECORDITEM();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSRECORDITEM_H
