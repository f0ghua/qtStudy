#ifndef VECTOR_CDD_CDDDBENUMRECORDITEM_H
#define VECTOR_CDD_CDDDBENUMRECORDITEM_H

#include "CDDDbENUMRECORDITEMImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ENUMRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEM : public CDDDbENUMRECORDITEMImpl
{
public:
    CDDDbENUMRECORDITEM();
    ~CDDDbENUMRECORDITEM();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMRECORDITEM_H
