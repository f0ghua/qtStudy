#ifndef VECTOR_CDD_CDDDBNEGRESCODEPROXYIMPL_H
#define VECTOR_CDD_CDDDBNEGRESCODEPROXYIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element NEGRESCODEPROXY
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODEPROXYImpl
{
public:
    CDDDbNEGRESCODEPROXYImpl();
    ~CDDDbNEGRESCODEPROXYImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODEPROXYIMPL_H
