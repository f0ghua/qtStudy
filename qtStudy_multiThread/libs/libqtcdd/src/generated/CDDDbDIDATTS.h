#ifndef VECTOR_CDD_CDDDBDIDATTS_H
#define VECTOR_CDD_CDDDBDIDATTS_H

#include "CDDDbDIDATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIDATTS
 *
 */
class VECTOR_CDD_API CDDDbDIDATTS : public CDDDbDIDATTSImpl
{
public:
    CDDDbDIDATTS();
    ~CDDDbDIDATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDATTS_H
