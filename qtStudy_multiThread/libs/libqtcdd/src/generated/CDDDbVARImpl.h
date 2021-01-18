#ifndef VECTOR_CDD_CDDDBVARIMPL_H
#define VECTOR_CDD_CDDDBVARIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIAGCLASS;
class CDDDbDIAGINST;
class CDDDbDIAGINSTREF;
class CDDDbDIDREFS;
class CDDDbJOBCNR;
class CDDDbJOBCNRREF;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element VAR
 *
 */
class VECTOR_CDD_API CDDDbVARImpl
{
public:
    CDDDbVARImpl();
    ~CDDDbVARImpl();

    void load(const QDomElement &element);

    /** @attribute base */
    QString m_base;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DIAGCLASS */
    QMap<QString, QSharedPointer<CDDDbDIAGCLASS>> m_elDiagclasss;

    /** @element DIAGINST */
    QMap<QString, QSharedPointer<CDDDbDIAGINST>> m_elDiaginsts;

    /** @element DIAGINSTREF */
    QVector<QSharedPointer<CDDDbDIAGINSTREF>> m_elDiaginstrefs;

    /** @element DIDREFS */
    QSharedPointer<CDDDbDIDREFS> m_elDidrefs;

    /** @element JOBCNR */
    QMap<QString, QSharedPointer<CDDDbJOBCNR>> m_elJobcnrs;

    /** @element JOBCNRREF */
    QVector<QSharedPointer<CDDDbJOBCNRREF>> m_elJobcnrrefs;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVARIMPL_H
