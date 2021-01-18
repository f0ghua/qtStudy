#ifndef VECTOR_CDD_CDDDBGAPDATAOBJ_H
#define VECTOR_CDD_CDDDBGAPDATAOBJ_H

#include "CDDDbGAPDATAOBJImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element GAPDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbGAPDATAOBJ : public CDDDbGAPDATAOBJImpl
{
public:
    CDDDbGAPDATAOBJ();
    ~CDDDbGAPDATAOBJ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGAPDATAOBJ_H
