#ifndef VECTOR_CDD_CDDDBDIDREFS_H
#define VECTOR_CDD_CDDDBDIDREFS_H

#include "CDDDbDIDREFSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIDREFS
 *
 */
class VECTOR_CDD_API CDDDbDIDREFS : public CDDDbDIDREFSImpl
{
public:
    CDDDbDIDREFS();
    ~CDDDbDIDREFS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREFS_H
