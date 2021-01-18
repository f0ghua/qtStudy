#ifndef VECTOR_CDD_CDDDBECUATTS_H
#define VECTOR_CDD_CDDDBECUATTS_H

#include "CDDDbECUATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ECUATTS
 *
 */
class VECTOR_CDD_API CDDDbECUATTS : public CDDDbECUATTSImpl
{
public:
    CDDDbECUATTS();
    ~CDDDbECUATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUATTS_H
