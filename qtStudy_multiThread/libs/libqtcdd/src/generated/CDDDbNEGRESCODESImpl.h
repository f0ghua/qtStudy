#ifndef VECTOR_CDD_CDDDBNEGRESCODESIMPL_H
#define VECTOR_CDD_CDDDBNEGRESCODESIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNEGRESCODE;

/**
 * @brief element NEGRESCODES
 *
 */
class VECTOR_CDD_API CDDDbNEGRESCODESImpl
{
public:
    CDDDbNEGRESCODESImpl();
    ~CDDDbNEGRESCODESImpl();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

    /** @attribute bo */
    QString m_bo;

    /** @attribute stateGroupDefault */
    QString m_stateGroupDefault;

    QString m_text;

    /** @element NEGRESCODE */
    QMap<QString, QSharedPointer<CDDDbNEGRESCODE>> m_elNegrescodes;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGRESCODESIMPL_H
