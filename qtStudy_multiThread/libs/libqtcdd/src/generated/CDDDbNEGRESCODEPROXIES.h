#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNEGRESCODEPROXY;

/**
 * @brief element NEGRESCODEPROXIES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXIES
{
public:
    CDDDbNEGRESCODEPROXIES();
    ~CDDDbNEGRESCODEPROXIES();

    void load(const QDomElement &element);

    /** @element NEGRESCODEPROXY */
    QVector<QSharedPointer<CDDDbNEGRESCODEPROXY>> m_negrescodeproxys;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXIES_H
