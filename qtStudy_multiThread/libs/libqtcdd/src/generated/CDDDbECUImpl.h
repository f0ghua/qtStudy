#ifndef VECTOR_CDD_CDDDBECUIMPL_H
#define VECTOR_CDD_CDDDBECUIMPL_H

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
class VECTOR_CDD_API CDDDbECUImpl
{
public:
    CDDDbECUImpl();
    ~CDDDbECUImpl();

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

    QString m_text;

    /** @element CSTR */
    QVector<QSharedPointer<CDDDbCSTR>> m_elCstrs;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element ENUM */
    QVector<QSharedPointer<CDDDbENUM>> m_elEnums;

    /** @element FAULTMEMORY */
    QSharedPointer<CDDDbFAULTMEMORY> m_elFaultmemory;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element UNS */
    QVector<QSharedPointer<CDDDbUNS>> m_elUnss;

    /** @element VAR */
    QMap<QString, QSharedPointer<CDDDbVAR>> m_elVars;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUIMPL_H
