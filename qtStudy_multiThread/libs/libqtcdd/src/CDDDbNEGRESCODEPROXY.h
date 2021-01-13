#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXY_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXY_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element NEGRESCODEPROXY
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXY
{
public:
    CDDDbNEGRESCODEPROXY();
    ~CDDDbNEGRESCODEPROXY();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXY_H
