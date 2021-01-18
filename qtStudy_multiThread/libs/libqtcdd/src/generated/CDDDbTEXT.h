#ifndef VECTOR_CDD_CDDDBTEXT_H
#define VECTOR_CDD_CDDDBTEXT_H

#include "CDDDbTEXTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TEXT
 *
 */
class VECTOR_CDD_API CDDDbTEXT : public CDDDbTEXTImpl
{
public:
    CDDDbTEXT();
    ~CDDDbTEXT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXT_H
