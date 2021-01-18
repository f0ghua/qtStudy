#ifndef VECTOR_CDD_CDDDBDATAOBJ_H
#define VECTOR_CDD_CDDDBDATAOBJ_H

#include "CDDDbDATAOBJImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbDATAOBJ : public CDDDbDATAOBJImpl
{
public:
    CDDDbDATAOBJ();
    ~CDDDbDATAOBJ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJ_H
