#ifndef VECTOR_CDD_CDDDBUNIT_H
#define VECTOR_CDD_CDDDBUNIT_H

#include "CDDDbUNITImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNIT
 *
 */
class VECTOR_CDD_API CDDDbUNIT : public CDDDbUNITImpl
{
public:
    CDDDbUNIT();
    ~CDDDbUNIT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNIT_H
