#ifndef VECTOR_CDD_CDDDBLINCOMP_H
#define VECTOR_CDD_CDDDBLINCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMP;
class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;

/**
 * @brief element LINCOMP
 *
 */
class VECTOR_CDD_API CDDDbLINCOMP
{
public:
    CDDDbLINCOMP();
    ~CDDDbLINCOMP();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element COMP */
    QSharedPointer<CDDDbCOMP> m_comp;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_cvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_pvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLINCOMP_H
