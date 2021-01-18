#ifndef VECTOR_CDD_CDDDBSHPROXYATTS_H
#define VECTOR_CDD_CDDDBSHPROXYATTS_H

#include "CDDDbSHPROXYATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHPROXYATTS
 *
 */
class VECTOR_CDD_API CDDDbSHPROXYATTS : public CDDDbSHPROXYATTSImpl
{
public:
    CDDDbSHPROXYATTS();
    ~CDDDbSHPROXYATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXYATTS_H
