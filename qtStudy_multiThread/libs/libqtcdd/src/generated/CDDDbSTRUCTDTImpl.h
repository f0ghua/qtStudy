#ifndef VECTOR_CDD_CDDDBSTRUCTDTIMPL_H
#define VECTOR_CDD_CDDDBSTRUCTDTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbDATAOBJ;
class CDDDbGAPDATAOBJ;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbSTRUCT;

/**
 * @brief element STRUCTDT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTDTImpl
{
public:
    CDDDbSTRUCTDTImpl();
    ~CDDDbSTRUCTDTImpl();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute showContOnly */
    QString m_showContOnly;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element DATAOBJ */
    QMap<QString, QSharedPointer<CDDDbDATAOBJ>> m_elDataobjs;

    /** @element GAPDATAOBJ */
    QVector<QSharedPointer<CDDDbGAPDATAOBJ>> m_elGapdataobjs;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STRUCT */
    QVector<QSharedPointer<CDDDbSTRUCT>> m_elStructs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTDTIMPL_H
