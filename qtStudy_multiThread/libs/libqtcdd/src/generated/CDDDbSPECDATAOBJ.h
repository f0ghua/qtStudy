#ifndef VECTOR_CDD_CDDDBSPECDATAOBJ_H
#define VECTOR_CDD_CDDDBSPECDATAOBJ_H

#include "CDDDbSPECDATAOBJImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SPECDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbSPECDATAOBJ : public CDDDbSPECDATAOBJImpl
{
public:
    CDDDbSPECDATAOBJ();
    ~CDDDbSPECDATAOBJ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECDATAOBJ_H
