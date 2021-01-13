#ifndef VECTOR_CDD_CDDDBECU_H
#define VECTOR_CDD_CDDDBECU_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTR;
class CDDDbDESC;
class CDDDbENUM;
class CDDDbFAULTMEMORY;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbUNS;
class CDDDbVAR;

/**
 * @brief element ECU
 *
 */
class VECTOR_CDD_API CDDDbECU
{
public:
    CDDDbECU();
    ~CDDDbECU();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute maxCombinedServiceIds */
    QString m_maxCombinedServiceIds;

    /** @attribute maxEcuSchedulerIds */
    QString m_maxEcuSchedulerIds;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CSTR */
    QSharedPointer<CDDDbCSTR> m_cstr;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element ENUM */
    QSharedPointer<CDDDbENUM> m_enum;

    /** @element FAULTMEMORY */
    QSharedPointer<CDDDbFAULTMEMORY> m_faultmemory;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element UNS */
    QVector<QSharedPointer<CDDDbUNS>> m_unss;

    /** @element VAR */
    QMap<QString, QSharedPointer<CDDDbVAR>> m_vars;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECU_H
