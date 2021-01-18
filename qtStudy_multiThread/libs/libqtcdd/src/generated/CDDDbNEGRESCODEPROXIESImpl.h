#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXIESIMPL_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXIESIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNEGRESCODEPROXY;

/**
 * @brief element NEGRESCODEPROXIES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXIESImpl
{
public:
    CDDDbNEGRESCODEPROXIESImpl();
    ~CDDDbNEGRESCODEPROXIESImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element NEGRESCODEPROXY */
    QVector<QSharedPointer<CDDDbNEGRESCODEPROXY>> m_elNegrescodeproxys;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXIESIMPL_H
