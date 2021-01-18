#ifndef VECTOR_CDD_CDDDBCSTR_H
#define VECTOR_CDD_CDDDBCSTR_H

#include "CDDDbCSTRImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CSTR
 *
 */
class VECTOR_CDD_API CDDDbCSTR : public CDDDbCSTRImpl
{
public:
    CDDDbCSTR();
    ~CDDDbCSTR();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTR_H
