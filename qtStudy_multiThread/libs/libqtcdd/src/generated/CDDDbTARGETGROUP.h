#ifndef VECTOR_CDD_CDDDBTARGETGROUP_H
#define VECTOR_CDD_CDDDBTARGETGROUP_H

#include "CDDDbTARGETGROUPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TARGETGROUP
 *
 */
class VECTOR_CDD_API CDDDbTARGETGROUP : public CDDDbTARGETGROUPImpl
{
public:
    CDDDbTARGETGROUP();
    ~CDDDbTARGETGROUP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTARGETGROUP_H
