#ifndef VECTOR_CDD_CDDDBNEGRESCODE_H
#define VECTOR_CDD_CDDDBNEGRESCODE_H

#include "CDDDbNEGRESCODEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NEGRESCODE
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODE : public CDDDbNEGRESCODEImpl
{
public:
    CDDDbNEGRESCODE();
    ~CDDDbNEGRESCODE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODE_H
