#ifndef VECTOR_CDD_CDDDBSTRUCTDT_H
#define VECTOR_CDD_CDDDBSTRUCTDT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbSTRUCT;

/**
 * @brief element STRUCTDT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTDT
{
public:
    CDDDbSTRUCTDT();
    ~CDDDbSTRUCTDT();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

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

    /** @element STRUCT */
    QVector<QSharedPointer<CDDDbSTRUCT>> m_structs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTDT_H
