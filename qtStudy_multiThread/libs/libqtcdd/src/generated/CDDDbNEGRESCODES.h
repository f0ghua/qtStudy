#ifndef VECTOR_CDD_CDDDBNEGRESCODES_H
#define VECTOR_CDD_CDDDBNEGRESCODES_H

#include "CDDDbNEGRESCODESImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NEGRESCODES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODES : public CDDDbNEGRESCODESImpl
{
public:
    CDDDbNEGRESCODES();
    ~CDDDbNEGRESCODES();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODES_H
