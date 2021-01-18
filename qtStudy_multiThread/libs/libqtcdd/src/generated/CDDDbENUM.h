#ifndef VECTOR_CDD_CDDDBENUM_H
#define VECTOR_CDD_CDDDBENUM_H

#include "CDDDbENUMImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ENUM
 *
 */
class VECTOR_CDD_API CDDDbENUM : public CDDDbENUMImpl
{
public:
    CDDDbENUM();
    ~CDDDbENUM();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUM_H
