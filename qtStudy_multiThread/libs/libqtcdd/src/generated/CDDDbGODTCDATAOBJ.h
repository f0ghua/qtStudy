#ifndef VECTOR_CDD_CDDDBGODTCDATAOBJ_H
#define VECTOR_CDD_CDDDBGODTCDATAOBJ_H

#include "CDDDbGODTCDATAOBJImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element GODTCDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbGODTCDATAOBJ : public CDDDbGODTCDATAOBJImpl
{
public:
    CDDDbGODTCDATAOBJ();
    ~CDDDbGODTCDATAOBJ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGODTCDATAOBJ_H
