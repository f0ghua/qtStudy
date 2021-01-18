#ifndef VECTOR_CDD_CDDDBMOD_H
#define VECTOR_CDD_CDDDBMOD_H

#include "CDDDbMODImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element MOD
 *
 */
class VECTOR_CDD_API CDDDbMOD : public CDDDbMODImpl
{
public:
    CDDDbMOD();
    ~CDDDbMOD();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMOD_H
