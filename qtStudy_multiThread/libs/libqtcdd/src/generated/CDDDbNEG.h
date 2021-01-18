#ifndef VECTOR_CDD_CDDDBNEG_H
#define VECTOR_CDD_CDDDBNEG_H

#include "CDDDbNEGImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NEG
 *
 */
class VECTOR_CDD_API CDDDbNEG : public CDDDbNEGImpl
{
public:
    CDDDbNEG();
    ~CDDDbNEG();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEG_H
