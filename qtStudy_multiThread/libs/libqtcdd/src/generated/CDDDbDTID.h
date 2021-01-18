#ifndef VECTOR_CDD_CDDDBDTID_H
#define VECTOR_CDD_CDDDBDTID_H

#include "CDDDbDTIDImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DTID
 *
 */
class VECTOR_CDD_API CDDDbDTID : public CDDDbDTIDImpl
{
public:
    CDDDbDTID();
    ~CDDDbDTID();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTID_H
