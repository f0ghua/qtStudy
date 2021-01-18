#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H

#include "CDDDbNEGRESCODEPROXIESImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NEGRESCODEPROXIES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXIES : public CDDDbNEGRESCODEPROXIESImpl
{
public:
    CDDDbNEGRESCODEPROXIES();
    ~CDDDbNEGRESCODEPROXIES();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H
