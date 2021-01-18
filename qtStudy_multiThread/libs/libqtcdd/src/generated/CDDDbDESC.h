#ifndef VECTOR_CDD_CDDDBDESC_H
#define VECTOR_CDD_CDDDBDESC_H

#include "CDDDbDESCImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DESC
 *
 */
class VECTOR_CDD_API CDDDbDESC : public CDDDbDESCImpl
{
public:
    CDDDbDESC();
    ~CDDDbDESC();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDESC_H
