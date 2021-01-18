#ifndef VECTOR_CDD_CDDDBMUXDT_H
#define VECTOR_CDD_CDDDBMUXDT_H

#include "CDDDbMUXDTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element MUXDT
 *
 */
class VECTOR_CDD_API CDDDbMUXDT : public CDDDbMUXDTImpl
{
public:
    CDDDbMUXDT();
    ~CDDDbMUXDT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMUXDT_H
