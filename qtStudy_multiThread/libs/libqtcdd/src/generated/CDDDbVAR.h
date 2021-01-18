#ifndef VECTOR_CDD_CDDDBVAR_H
#define VECTOR_CDD_CDDDBVAR_H

#include "CDDDbVARImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element VAR
 *
 */
class VECTOR_CDD_API CDDDbVAR : public CDDDbVARImpl
{
public:
    CDDDbVAR();
    ~CDDDbVAR();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVAR_H
