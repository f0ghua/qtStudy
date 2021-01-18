#ifndef VECTOR_CDD_CDDDBVCKMGR_H
#define VECTOR_CDD_CDDDBVCKMGR_H

#include "CDDDbVCKMGRImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element VCKMGR
 *
 */
class VECTOR_CDD_API CDDDbVCKMGR : public CDDDbVCKMGRImpl
{
public:
    CDDDbVCKMGR();
    ~CDDDbVCKMGR();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVCKMGR_H
