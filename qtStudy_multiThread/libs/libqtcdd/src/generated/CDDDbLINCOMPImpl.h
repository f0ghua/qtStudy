#ifndef VECTOR_CDD_CDDDBLINCOMPIMPL_H
#define VECTOR_CDD_CDDDBLINCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMP;
class CDDDbCVALUETYPE;
class CDDDbEXCL;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;

/**
 * @brief element LINCOMP
 *
 */
class VECTOR_CDD_API CDDDbLINCOMPImpl
{
public:
    CDDDbLINCOMPImpl();
    ~CDDDbLINCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element COMP */
    QSharedPointer<CDDDbCOMP> m_elComp;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element EXCL */
    QVector<QSharedPointer<CDDDbEXCL>> m_elExcls;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLINCOMPIMPL_H
