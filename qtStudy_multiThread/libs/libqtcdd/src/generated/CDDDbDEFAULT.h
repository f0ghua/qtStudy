#ifndef VECTOR_CDD_CDDDBDEFAULT_H
#define VECTOR_CDD_CDDDBDEFAULT_H

#include "CDDDbDEFAULTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DEFAULT
 *
 */
class VECTOR_CDD_API CDDDbDEFAULT : public CDDDbDEFAULTImpl
{
public:
    CDDDbDEFAULT();
    ~CDDDbDEFAULT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFAULT_H
