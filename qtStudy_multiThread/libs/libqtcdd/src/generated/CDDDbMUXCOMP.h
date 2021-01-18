#ifndef VECTOR_CDD_CDDDBMUXCOMP_H
#define VECTOR_CDD_CDDDBMUXCOMP_H

#include "CDDDbMUXCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element MUXCOMP
 *
 */
class VECTOR_CDD_API CDDDbMUXCOMP : public CDDDbMUXCOMPImpl
{
public:
    CDDDbMUXCOMP();
    ~CDDDbMUXCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMUXCOMP_H
