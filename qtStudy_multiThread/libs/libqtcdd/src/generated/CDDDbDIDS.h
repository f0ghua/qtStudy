#ifndef VECTOR_CDD_CDDDBDIDS_H
#define VECTOR_CDD_CDDDBDIDS_H

#include "CDDDbDIDSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIDS
 *
 */
class VECTOR_CDD_API CDDDbDIDS : public CDDDbDIDSImpl
{
public:
    CDDDbDIDS();
    ~CDDDbDIDS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDS_H
