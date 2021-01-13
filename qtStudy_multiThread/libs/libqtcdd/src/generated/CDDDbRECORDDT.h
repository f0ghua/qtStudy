#ifndef VECTOR_CDD_CDDDBRECORDDT_H
#define VECTOR_CDD_CDDDBRECORDDT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbRECORD;

/**
 * @brief element RECORDDT
 *
 */
class VECTOR_CDD_API CDDDbRECORDDT
{
public:
    CDDDbRECORDDT();
    ~CDDDbRECORDDT();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute rtSpec */
    QString m_rtSpec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_cvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_pvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element RECORD */
    QMap<QString, QSharedPointer<CDDDbRECORD>> m_records;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDT_H
