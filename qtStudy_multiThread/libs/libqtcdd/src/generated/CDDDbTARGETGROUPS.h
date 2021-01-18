#ifndef VECTOR_CDD_CDDDBTARGETGROUPS_H
#define VECTOR_CDD_CDDDBTARGETGROUPS_H

#include "CDDDbTARGETGROUPSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TARGETGROUPS
 *
 */
class VECTOR_CDD_API CDDDbTARGETGROUPS : public CDDDbTARGETGROUPSImpl
{
public:
    CDDDbTARGETGROUPS();
    ~CDDDbTARGETGROUPS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTARGETGROUPS_H
