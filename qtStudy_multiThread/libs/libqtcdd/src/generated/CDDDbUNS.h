#ifndef VECTOR_CDD_CDDDBUNS_H
#define VECTOR_CDD_CDDDBUNS_H

#include "CDDDbUNSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNS
 *
 */
class VECTOR_CDD_API CDDDbUNS : public CDDDbUNSImpl
{
public:
    CDDDbUNS();
    ~CDDDbUNS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNS_H
