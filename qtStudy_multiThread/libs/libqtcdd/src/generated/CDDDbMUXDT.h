#ifndef VECTOR_CDD_CDDDBMUXDT_H
#define VECTOR_CDD_CDDDBMUXDT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCASE;
class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbSTRUCTURE;

/**
 * @brief element MUXDT
 *
 */
class VECTOR_CDD_API CDDDbMUXDT
{
public:
    CDDDbMUXDT();
    ~CDDDbMUXDT();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CASE */
    QVector<QSharedPointer<CDDDbCASE>> m_cases;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_cvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_pvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_structure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMUXDT_H
