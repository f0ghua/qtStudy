#ifndef VECTOR_CDD_CDDDBDID_H
#define VECTOR_CDD_CDDDBDID_H

#include "CDDDbDIDImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DID
 *
 */
class VECTOR_CDD_API CDDDbDID : public CDDDbDIDImpl
{
public:
    CDDDbDID();
    ~CDDDbDID();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDID_H
