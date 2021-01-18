#ifndef VECTOR_CDD_CDDDBSHPROXY_H
#define VECTOR_CDD_CDDDBSHPROXY_H

#include "CDDDbSHPROXYImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHPROXY
 *
 */
class VECTOR_CDD_API CDDDbSHPROXY : public CDDDbSHPROXYImpl
{
public:
    CDDDbSHPROXY();
    ~CDDDbSHPROXY();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXY_H
