#ifndef VECTOR_CDD_CDDDBVARATTS_H
#define VECTOR_CDD_CDDDBVARATTS_H

#include "CDDDbVARATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element VARATTS
 *
 */
class VECTOR_CDD_API CDDDbVARATTS : public CDDDbVARATTSImpl
{
public:
    CDDDbVARATTS();
    ~CDDDbVARATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVARATTS_H
