#ifndef VECTOR_CDD_CDDDBDIDREF_H
#define VECTOR_CDD_CDDDBDIDREF_H

#include "CDDDbDIDREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIDREF
 *
 */
class VECTOR_CDD_API CDDDbDIDREF : public CDDDbDIDREFImpl
{
public:
    CDDDbDIDREF();
    ~CDDDbDIDREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREF_H
