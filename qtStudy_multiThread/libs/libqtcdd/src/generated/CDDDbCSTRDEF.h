#ifndef VECTOR_CDD_CDDDBCSTRDEF_H
#define VECTOR_CDD_CDDDBCSTRDEF_H

#include "CDDDbCSTRDEFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CSTRDEF
 *
 */
class VECTOR_CDD_API CDDDbCSTRDEF : public CDDDbCSTRDEFImpl
{
public:
    CDDDbCSTRDEF();
    ~CDDDbCSTRDEF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTRDEF_H
