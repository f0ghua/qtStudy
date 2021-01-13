#ifndef VECTOR_CDD_CDDDBSTATEGROUP_H
#define VECTOR_CDD_CDDDBSTATEGROUP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbNEGRESCODEPROXY;
class CDDDbQUAL;
class CDDDbSTATE;

/**
 * @brief element STATEGROUP
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUP
{
public:
    CDDDbSTATEGROUP();
    ~CDDDbSTATEGROUP();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element NEGRESCODEPROXY */
    QSharedPointer<CDDDbNEGRESCODEPROXY> m_negrescodeproxy;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STATE */
    QVector<QSharedPointer<CDDDbSTATE>> m_states;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUP_H
