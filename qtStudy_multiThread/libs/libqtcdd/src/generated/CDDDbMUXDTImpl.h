#ifndef VECTOR_CDD_CDDDBMUXDTIMPL_H
#define VECTOR_CDD_CDDDBMUXDTIMPL_H

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
class VECTOR_CDD_API CDDDbMUXDTImpl
{
public:
    CDDDbMUXDTImpl();
    ~CDDDbMUXDTImpl();

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

    QString m_text;

    /** @element CASE */
    QVector<QSharedPointer<CDDDbCASE>> m_elCases;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_elStructure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMUXDTIMPL_H
