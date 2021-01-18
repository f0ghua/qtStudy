#ifndef VECTOR_CDD_CDDDBRECORDDATAOBJ_H
#define VECTOR_CDD_CDDDBRECORDDATAOBJ_H

#include "CDDDbRECORDDATAOBJImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbRECORDDATAOBJ : public CDDDbRECORDDATAOBJImpl
{
public:
    CDDDbRECORDDATAOBJ();
    ~CDDDbRECORDDATAOBJ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDATAOBJ_H
