#ifndef VECTOR_CDD_CDDDBVAR_H
#define VECTOR_CDD_CDDDBVAR_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIAGCLASS;
class CDDDbDIAGINST;
class CDDDbDIDREFS;
class CDDDbJOBCNR;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element VAR
 *
 */
class VECTOR_CDD_API CDDDbVAR
{
public:
    CDDDbVAR();
    ~CDDDbVAR();

    void load(const QDomElement &element);

    /** @attribute base */
    QString m_base;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element DIAGCLASS */
    QMap<QString, QSharedPointer<CDDDbDIAGCLASS>> m_diagclasss;

    /** @element DIAGINST */
    QMap<QString, QSharedPointer<CDDDbDIAGINST>> m_diaginsts;

    /** @element DIDREFS */
    QSharedPointer<CDDDbDIDREFS> m_didrefs;

    /** @element JOBCNR */
    QSharedPointer<CDDDbJOBCNR> m_jobcnr;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVAR_H
