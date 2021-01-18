#ifndef VECTOR_CDD_CDDDBSTATEGROUPIMPL_H
#define VECTOR_CDD_CDDDBSTATEGROUPIMPL_H

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
class VECTOR_CDD_API CDDDbSTATEGROUPImpl
{
public:
    CDDDbSTATEGROUPImpl();
    ~CDDDbSTATEGROUPImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element NEGRESCODEPROXY */
    QVector<QSharedPointer<CDDDbNEGRESCODEPROXY>> m_elNegrescodeproxys;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STATE */
    QVector<QSharedPointer<CDDDbSTATE>> m_elStates;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPIMPL_H
