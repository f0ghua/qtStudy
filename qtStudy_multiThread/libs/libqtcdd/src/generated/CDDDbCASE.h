#ifndef VECTOR_CDD_CDDDBCASE_H
#define VECTOR_CDD_CDDDBCASE_H

#include "CDDDbCASEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CASE
 *
 */
class VECTOR_CDD_API CDDDbCASE : public CDDDbCASEImpl
{
public:
    CDDDbCASE();
    ~CDDDbCASE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCASE_H
