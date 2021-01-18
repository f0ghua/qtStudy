#ifndef VECTOR_CDD_CDDDBDIAGINSTREF_H
#define VECTOR_CDD_CDDDBDIAGINSTREF_H

#include "CDDDbDIAGINSTREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIAGINSTREF
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTREF : public CDDDbDIAGINSTREFImpl
{
public:
    CDDDbDIAGINSTREF();
    ~CDDDbDIAGINSTREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTREF_H
