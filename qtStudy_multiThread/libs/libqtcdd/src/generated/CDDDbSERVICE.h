#ifndef VECTOR_CDD_CDDDBSERVICE_H
#define VECTOR_CDD_CDDDBSERVICE_H

#include "CDDDbSERVICEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SERVICE
 *
 */
class VECTOR_CDD_API CDDDbSERVICE : public CDDDbSERVICEImpl
{
public:
    CDDDbSERVICE();
    ~CDDDbSERVICE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSERVICE_H
