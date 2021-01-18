#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXY_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXY_H

#include "CDDDbNEGRESCODEPROXYImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NEGRESCODEPROXY
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXY : public CDDDbNEGRESCODEPROXYImpl
{
public:
    CDDDbNEGRESCODEPROXY();
    ~CDDDbNEGRESCODEPROXY();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXY_H
