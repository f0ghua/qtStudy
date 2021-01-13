#ifndef VECTOR_CDD_CDDDBNEGRESCODES_H
#define VECTOR_CDD_CDDDBNEGRESCODES_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNEGRESCODE;

/**
 * @brief element NEGRESCODES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODES
{
public:
    CDDDbNEGRESCODES();
    ~CDDDbNEGRESCODES();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

    /** @attribute bo */
    QString m_bo;

    /** @attribute stateGroupDefault */
    QString m_stateGroupDefault;

    /** @element NEGRESCODE */
    QMap<QString, QSharedPointer<CDDDbNEGRESCODE>> m_negrescodes;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODES_H
