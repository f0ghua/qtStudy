#ifndef VECTOR_CDD_CDDDBUNSDEF_H
#define VECTOR_CDD_CDDDBUNSDEF_H

#include "CDDDbUNSDEFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNSDEF
 *
 */
class VECTOR_CDD_API CDDDbUNSDEF : public CDDDbUNSDEFImpl
{
public:
    CDDDbUNSDEF();
    ~CDDDbUNSDEF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSDEF_H
