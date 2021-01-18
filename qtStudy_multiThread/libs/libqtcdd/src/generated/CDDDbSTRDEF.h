#ifndef VECTOR_CDD_CDDDBSTRDEF_H
#define VECTOR_CDD_CDDDBSTRDEF_H

#include "CDDDbSTRDEFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STRDEF
 *
 */
class VECTOR_CDD_API CDDDbSTRDEF : public CDDDbSTRDEFImpl
{
public:
    CDDDbSTRDEF();
    ~CDDDbSTRDEF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRDEF_H
