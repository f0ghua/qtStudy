#ifndef VECTOR_CDD_CDDDBPOS_H
#define VECTOR_CDD_CDDDBPOS_H

#include "CDDDbPOSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element POS
 *
 */
class VECTOR_CDD_API CDDDbPOS : public CDDDbPOSImpl
{
public:
    CDDDbPOS();
    ~CDDDbPOS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPOS_H
